# SPDX-License-Identifier: Apache-2.0
# SPDX-FileCopyrightText: Canonical Ltd.

CFLAGS ?=
CPPFLAGS ?=
LDFLAGS ?=
LDLIBS ?=
DESTDIR ?=
TARGET_ARCH ?=
EXEEXT ?=

CFLAGS += -Wall

# Show the effective values we build with.
$(foreach v,CFLAGS CPPFLAGS LDFLAGS LDLIBS DESTDIR TARGET_TARCH,$(info $v=$(value $v)))

prefix ?= /usr/local
exec_prefix ?= $(prefix)
bindir ?= $(exec_prefix)/bin

.PHONY: all
all: dlopen-tool$(EXEEXT)

.PHONY: clean
clean:
	rm -f dlopen-tool$(EXEEXT)

.PHONY: install
install: $(DESTDIR)$(bindir)/dlopen-tool$(EXEEXT)

.PHONY: fmt
fmt:
	clang-format -i main.c

dlopen-tool$(EXEEXT): LDLIBS=-ldl
dlopen-tool$(EXEEXT): main.c
	$(LINK.c) $(OUTPUT_OPTION) $< $(LDLIBS)
$(DESTDIR)$(bindir)/dlopen-tool$(EXEEXT): dlopen-tool$(EXEEXT) | $(DESTDIR)$(bindir)
	install -m 755 $< $@
$(DESTDIR)$(bindir):
	install -d -m 755 $@
