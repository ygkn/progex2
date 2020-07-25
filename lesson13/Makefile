#
#  Makefile
#

## source, header, object and executable files
EXES    = prog13-1 prog13-2 prog13-3 prog13-4
LIBS 	= list-check.o tree-check.o queue.o

## commands and options
CC      = gcc
CFLAGS  =
LINKER  = gcc
LNFLAGS =

## make rules
all:    $(LIBS) $(EXES)

clean: 
	rm -f $(EXES) $(LIBS) a.out core *~

## suffix rules
.SUFFIXES: .c
.c.o:
	$(CC) $(CFLAGS) -c $<

%: %.c
	$(LINKER) $(LNFLAGS) $^ -o $@

## dependence of objejt, source and header files
prog13-1:   	list-check.o
prog13-2:   	tree-check.o queue.o
prog13-3:   	tree-check.o queue.o
prog13-4:   	tree-check.o queue.o
liost-check.o:	list-common.h
tree-check.o:   tree-common.h
queue.o:        queue.h tree-common.h
