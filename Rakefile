require 'active_support'
require 'json'
require 'know/ontology'
require 'rdf'
require 'rdf/turtle'

include ActiveSupport::Inflector
include RDF

ActiveSupport::Inflector.inflections(:en) do |inflect|
  inflect.irregular 'cafe', 'cafes'
end

task default: %w(codegen)

HEADER = <<~EOF
  /* This is free and unencumbered software released into the public domain. */

  #pragma once
EOF

def c_name(concept_name)
  underscore(concept_name.to_s)
end

file 'src/know/classes.h' => %w(../know.ttl) do |t|
  ontology = Know::Ontology.load(t.prerequisites.first)
  File.open(t.name, 'w') do |out|
    out.puts HEADER
    out.puts
    ontology.classes.each do |klass|
      class_name = c_name(klass.name)
      out.puts %Q[#include "classes/#{class_name}.h"]
    end
  end
end

task :codegen => %w(../know.ttl src/know/classes.h) do |t|
  ontology = Know::Ontology.load(t.prerequisites.first)
  ontology.classes.each do |klass|
    class_name = c_name(klass.name)
    File.open("src/know/classes/#{class_name}.h", 'w') do |out|
      class_name = "#{class_name}_" if %w(class).include?(class_name) # reserved words
      out.puts HEADER
      out.puts
      out.puts "typedef struct {"
      klass.properties.each do |property|
        property_name = c_name(property.name)
        property_name = pluralize(property_name) unless property.functional?
        property_type = property.range
        property_type = case property_type
          when ::Know::Ontology::Concept then "#{c_name(property_type.name)}*"
          when ::XSD.anyURI then 'char*'
          when ::XSD.dateTime then :time_t
          when ::XSD.language then 'char*'
          when ::XSD.nonNegativeInteger then :uint64_t
          when ::XSD.string then 'char*'
          else 'void*'
        end
        property_type << '*' unless property.functional?
        out.puts "  #{property_type} #{property_name};"
      end
      out.puts "} #{class_name};"
    end
  end
end
