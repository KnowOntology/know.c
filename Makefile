CC = clang
CFLAGS = -std=c11
INSTALL = install
INSTALL_DATA = $(INSTALL) -m 644
VERSION = $(shell cat VERSION)

prefix := /usr/local
includedir := $(prefix)/include

all: src/know.h

check: src/know.h
	$(CC) -fsyntax-only $(CFLAGS) $<

install: src/know.h
	mkdir -p $(DESTDIR)$(includedir)/
	$(INSTALL_DATA) $^ $(DESTDIR)$(includedir)/

uninstall:
	rm -f $(DESTDIR)$(includedir)/know.h

clean:
	@rm -f *~

distclean: clean

mostlyclean: clean

maintainer-clean: clean

.PHONY: all check install uninstall
.PHONY: clean distclean mostlyclean maintainer-clean
.SECONDARY:
.SUFFIXES:
