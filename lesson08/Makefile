#
#  Makefile
#

## source, header, object and executable files
EXES 	= prog8-1 prog8-2 prog8-3 prog8-4 prog8-5
LIBS 	= sort-check.o measurement.o

## commands and options
CC      = gcc
CFLAGS  =
LINKER  = gcc
LNFLAGS =

filename = /etc/redhat-release
fileexists = $(shell ls ${filename} | grep ${filename})
ifeq (${fileexists}, ${filename})
libc = $(shell rpm -q glibc)
libc_version = $(shell rpm -q glibc | grep 2.12)
ifeq (${libc}, ${libc_version})
LIBTIME = -lrt
else
LIBTIME =
endif
else
LIBTIME =
endif

## make rules
all:	$(LIBS) $(EXES)

clean: 
	rm -f $(EXES) $(LIBS) a.out core *~

## suffix rules
.SUFFIXES: .c
.c.o:
	$(CC) $(CFLAGS) -c $<

prog8-5: prog8-5.c
	$(LINKER) $(LNFLAGS) $(LIBTIME) $^ -o $@

%: %.c
	$(LINKER) $(LNFLAGS) $^ -o $@

## dependence of objejt, source and header files
prog8-1:	sort-check.o
prog8-2:	sort-check.o
prog8-3:	sort-check.o
prog8-4:	sort-check.o
prog8-5:	sort-check.o measurement.o
sort-check.o:	sort-common.h
measurement.o:	measurement.h sort-common.h
