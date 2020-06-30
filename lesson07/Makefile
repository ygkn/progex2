#
#  Makefile
#

## source, header, object and executable files
EXES 	= prog7-1 prog7-2 prog7-3 prog7-4

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
