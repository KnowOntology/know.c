CC = clang
CFLAGS = -std=c11
INSTALL = install
INSTALL_DATA = $(INSTALL) -m 644

prefix := /usr/local
includedir := $(prefix)/include

SOURCES := $(wildcard src/*.h src/*/*.h src/*/*/*.h)
VERSION := $(shell cat VERSION)

all: $(SOURCES)

check: $(SOURCES)
	$(CC) -fsyntax-only $(CFLAGS) $<

install: installdirs $(SOURCES)
	$(INSTALL_DATA) src/know.h $(DESTDIR)$(includedir)/
	$(INSTALL_DATA) src/know/*.h $(DESTDIR)$(includedir)/know/
	$(INSTALL_DATA) src/know/classes/*.h $(DESTDIR)$(includedir)/know/classes/

installdirs:
	$(INSTALL) -d $(DESTDIR)$(includedir)/
	$(INSTALL) -d $(DESTDIR)$(includedir)/know
	$(INSTALL) -d $(DESTDIR)$(includedir)/know/classes

uninstall:
	rm -f $(DESTDIR)$(includedir)/know.h
	rm -f $(DESTDIR)$(includedir)/know/classes.h
	rm -f $(DESTDIR)$(includedir)/know/classes/*.h

clean:
	@rm -f *~

distclean: clean

mostlyclean: clean

maintainer-clean: clean

.PHONY: all check install uninstall
.PHONY: clean distclean mostlyclean maintainer-clean
.SECONDARY:
.SUFFIXES:
