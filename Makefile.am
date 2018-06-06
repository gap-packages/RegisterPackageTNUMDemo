#
# RegisterPackageTNUMDemo: Demo for RegisterPackageTNUM functionality
#
# This file is part of the build system of a GAP kernel extension.
# Requires automake.
#
ACLOCAL_AMFLAGS = -I m4

BINARCHDIR = bin/$(GAPARCH)
GAPINSTALLLIB = $(abs_top_srcdir)/$(BINARCHDIR)/RegisterPackageTNUMDemo.so

lib_LTLIBRARIES = RegisterPackageTNUMDemo.la

RegisterPackageTNUMDemo_la_SOURCES = src/RegisterPackageTNUMDemo.c
RegisterPackageTNUMDemo_la_CPPFLAGS = $(GAP_CPPFLAGS)
RegisterPackageTNUMDemo_la_CFLAGS = $(GAP_CFLAGS)
RegisterPackageTNUMDemo_la_LDFLAGS = $(GAP_LDFLAGS) -module -avoid-version
if SYS_IS_CYGWIN
RegisterPackageTNUMDemo_la_LDFLAGS += -no-undefined -version-info 0:0:0 -Wl,$(GAPROOT)/bin/$(GAPARCH)/gap.dll
endif

all-local: RegisterPackageTNUMDemo.la
	$(mkdir_p) $(top_srcdir)/$(BINARCHDIR)
if SYS_IS_CYGWIN
	cp .libs/RegisterPackageTNUMDemo.dll $(GAPINSTALLLIB)
else
	cp .libs/RegisterPackageTNUMDemo.so $(GAPINSTALLLIB)
endif
	@echo "SUCCESS!"

distclean-local:
	rm -rf bin/*
	(cd doc ; ./clean)

doc: doc/manual.six

doc/manual.six: doc/*.xml PackageInfo.g
	($(GAPROOT)/bin/gap.sh -A makedoc.g)
