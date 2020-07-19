#
#  Makefile
#

## source, header, object and executable files
EXES 	= prog12-1 prog12-2 prog12-3 prog12-4 prog12-5
LIBS 	= arraytable-check.o chaintable-check.o measurement.o

## commands and options
CC      = gcc
CFLAGS =
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
all:    $(LIBS) $(EXES)

clean: 
	rm -f $(EXES) $(LIBS) a.out core *~

## suffix rules
.SUFFIXES: .c
.c.o:
	$(CC) $(CFLAGS) -c $<

prog12-5: prog12-5.c
	$(LINKER) $(LNFLAGS) $(LIBTIME) $^ -o $@

%: %.c
	$(LINKER) $(LNFLAGS) $^ -o $@

## dependence of objejt, source and header files
prog12-1:	arraytable-check.o
prog12-2:	arraytable-check.o
prog12-3:	chaintable-check.o
prog12-4:	arraytable-check.o
prog12-5:	arraytable-check.o chaintable-check.o measurement.o
arraytable-check.o:	arraytable-common.h
chaintable-check.o:	chaintable-common.h
measurement.o:		measurement.h arraytable-common.h chaintable-common.h

