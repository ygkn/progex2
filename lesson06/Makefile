#
#  Makefile
#

## source, header, object and executable files
EXES 	= prog6-1 prog6-2 prog6-3 prog6-4 prog6-5

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
