#
#  Makefile
#

## source, header, object and executable files
EXES 	= prog2-1 prog2-2 prog2-3 prog2-4 prog2-5

## commands and options
CC      = gcc
CFLAGS  =
        
## make rules
all:	$(EXES)

clean: 
	rm -f $(EXES) a.out core *~

## suffix rules
.SUFFIXES: .c
.c.o:
	$(CC) $(CFLAGS) $<

## dependence of objejt, source and header files
