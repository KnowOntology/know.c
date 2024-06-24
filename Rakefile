require 'active_support'
require 'know/ontology'
require 'rdf/turtle'
require 'stringio'

include ActiveSupport::Inflector, RDF

ActiveSupport::Inflector.inflections(:en) do |inflect|
  inflect.irregular 'cafe', 'cafes'
end

task default: %w(codegen)

HEADER = <<~EOF
  /* This is free and unencumbered software released into the public domain. */

  #pragma once
EOF

file 'src/know/classes.h' => %w(../know.ttl) do |t|
  ontology = Know::Ontology.load(t.prerequisites.first)
  File.open(t.name, 'w') do |out|
    out.puts HEADER
    out.puts
    ontology.classes.each do |klass|
      out.puts %Q[#include "classes/#{klass.c_file}"]
    end
  end
end

task :codegen => %w(../know.ttl src/know/classes.h) do |t|
  ontology = Know::Ontology.load(t.prerequisites.first)
  ontology.classes.each do |klass|
    filename = underscore(klass.name)
    File.open("src/know/classes/#{filename}.h", 'w') do |out_file|
      top, out = StringIO.new, StringIO.new
      includes = {}

      includes['stddef.h'] = "for NULL, size_t"
      includes['stdint.h'] = "for uint64_t"
      includes['stdlib.h'] = "for calloc(), free(), realloc()"
      includes['string.h'] = "for strdup()"
      includes['time.h']   = "for time_t"

      # Generate the `know_$CLASS_t` typedef:
      out.puts
      out.puts "typedef struct know_#{klass.c_name} {"
      klass.properties.each do |property|
        next if property.c_type.nil?
        out.puts "  #{property.c_type} #{property.c_name};"
      end
      out.puts "} #{klass.c_type};"

      # Generate the `know_$CLASS_alloc()` function:
      out.puts
      out.puts <<~EOF
        inline #{klass.c_type}* know_#{klass.c_name}_alloc() {
          return calloc(1, sizeof(#{klass.c_type}));
        }
      EOF

      # Generate the `know_$CLASSes_alloc()` function:
      out.puts
      out.puts <<~EOF
        inline #{klass.c_type}** know_#{pluralize(klass.c_name)}_alloc(const size_t count) {
          return calloc(count, sizeof(#{klass.c_type}*));
        }
      EOF

      # Generate the `know_$CLASS_clone()` function:
      out.puts
      out.puts <<~EOF
        inline #{klass.c_type}* know_#{klass.c_name}_clone(const #{klass.c_type}* thing) {
          #{klass.c_type}* clone = know_#{klass.c_name}_alloc();
      EOF
      klass.properties.each do |property|
        next if property.c_type.nil?
        if property.functional?
          if clone_func = property.c_clone_func
            out.puts <<~EOF.lines.each { |s| s.prepend('  ') }.join
              clone->#{property.c_name} = #{clone_func}(thing->#{property.c_name});
            EOF
          else
            out.puts <<~EOF.lines.each { |s| s.prepend('  ') }.join
              clone->#{property.c_name} = thing->#{property.c_name};
            EOF
          end
        else
          out.puts "  clone->#{property.c_name} = NULL; // TODO"
        end
      end
      out.puts <<~EOF
          return clone;
        }
      EOF

      # Generate the `know_$CLASSes_clone()` function:
      out.puts
      out.puts <<~EOF
        inline #{klass.c_type}** know_#{pluralize(klass.c_name)}_clone(const #{klass.c_type}** things) {
          return NULL; // TODO
        }
      EOF

      # Generate the `know_$CLASS_free()` function:
      out.puts
      out.puts <<~EOF
        inline void know_#{klass.c_name}_free(#{klass.c_type}* thing) {
          if (!thing) return;
      EOF
      klass.properties.each do |property|
        next if property.c_type.nil?
        next unless property.c_type.end_with?('*')
        free_func, clone_func = property.c_free_func || 'free', property.c_clone_func
        if property.functional?
          out.puts <<~EOF.lines.each { |s| s.prepend('  ') }.join
            if (thing->#{property.c_name}) {
              #{free_func}(thing->#{property.c_name});
              thing->#{property.c_name} = NULL;
            }
          EOF
        else
          out.puts <<~EOF.lines.each { |s| s.prepend('  ') }.join
            if (thing->#{property.c_name}) {
              // TODO: free any array elements with #{free_func}()
              free(thing->#{property.c_name});
              thing->#{property.c_name} = NULL;
            }
          EOF
        end
      end
      out.puts <<~EOF
          free(thing);
        }
      EOF

      # Generate the `know_$CLASSes_free()` function:
      out.puts
      out.puts <<~EOF
        inline void know_#{pluralize(klass.c_name)}_free(#{klass.c_type}** things) {
          // TODO
        }
      EOF

      # Generate the `know_$CLASS_$PROPERTY_*()` functions:
      klass.properties.each do |property|
        next if property.c_type.nil?
        out.puts
        free_func, clone_func = property.c_free_func, property.c_clone_func
        if property.functional?
          out.puts <<~EOF
            inline #{klass.c_type}* know_#{klass.c_name}_#{property.c_name}_clone(const #{klass.c_type}* thing) {
              return NULL; // TODO
            }
          EOF

          out.puts
          out.puts <<~EOF
            inline void know_#{klass.c_name}_#{property.c_name}_set(#{klass.c_type}* thing, const #{property.c_type} value) {
          EOF
          out.puts "  #{free_func}(thing->#{property.c_name});" if free_func
          if clone_func
            out.puts "  thing->#{property.c_name} = #{clone_func}(value);"
          else
            out.puts "  thing->#{property.c_name} = value;"
          end
          out.puts "}"
        else
          clone_type = property.c_type #"know_#{pluralize(property.range.c_name)}_clone" rescue 'know_strings_clone'
          clone_func = "know_#{pluralize(property.range.c_name)}_clone" rescue 'know_strings_clone'
          out.puts <<~EOF
            inline #{clone_type} know_#{klass.c_name}_#{property.c_name}_clone(const #{klass.c_type}* thing) {
              return #{clone_func}((const #{property.c_type})thing->#{property.c_name});
            }
          EOF
        end
      end

      # Begin generating the file header:
      top.puts HEADER

      # Generate standard library dependencies:
      top.puts unless includes.empty?
      top.puts "#define _POSIX_C_SOURCE 200809L"
      includes.each do |header, comment|
        header = "<#{header}>"
        top.puts "#include #{header.ljust(10)} // #{comment}"
      end

      # Generate internal dependencies:
      top.puts
      top.puts "#include \"_prelude.h\""
      klass.dependencies.each do |dependency|
        top.puts
        top.puts "typedef struct know_#{dependency.c_name} #{dependency.c_type};"
        top.puts "inline void know_#{dependency.c_name}_free(#{dependency.c_type}*);"
        top.puts "inline void know_#{pluralize(dependency.c_name)}_free(#{dependency.c_type}**);"
        top.puts "inline #{dependency.c_type}* know_#{dependency.c_name}_clone(const #{dependency.c_type}*);"
        top.puts "inline #{dependency.c_type}** know_#{pluralize(dependency.c_name)}_clone(const #{dependency.c_type}**);"
      end

      out_file.write top.string
      out_file.write out.string
    end
  end
end

class Know::Ontology::Class
  def c_file
    "#{self.c_name}.h"
  end

  def c_name
    underscore(self.name.to_s)
  end

  def c_type
    "know_#{self.c_name}_t"
  end

  def c_alloc_func
    "know_#{self.c_name}_alloc"
  end

  def c_free_func
    "know_#{self.c_name}_free"
  end

  def c_clone_func
    "know_#{self.c_name}_clone"
  end
end

class Know::Ontology::Property
  def c_name
    name = underscore(self.name.to_s)
    name = pluralize(name) unless self.functional?
    name
  end

  def c_type
    type = case type = self.range
      when ::Know::Ontology::Class then "struct know_#{type.c_name}*"
      when ::XSD.anyURI then 'char*'
      when ::XSD.dateTime then :time_t
      when ::XSD.language then 'char*'
      when ::XSD.nonNegativeInteger then :uint64_t
      when ::XSD.string then 'char*'
      else return nil
    end
    type << '*' unless self.functional?
    type
  end

  def c_alloc_func
    nil
  end

  def c_free_func
    case type = self.range
      when ::Know::Ontology::Class then type.c_free_func
      else case self.c_type
        when 'char*' then 'free'
        when 'char**' then 'know_strings_free'
        else nil
      end
    end
  end

  def c_clone_func
    case type = self.range
      when ::Know::Ontology::Class then "know_#{type.c_name}_clone"
      else case self.c_type
        when 'char*' then 'strdup'
        when 'char**' then 'know_strings_clone'
        else nil
      end
    end
  end
end
