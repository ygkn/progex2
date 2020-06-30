#
#  Makefile
#

## source, header, object and executable files
EXES 	= prog3-1 prog3-2 prog3-3 prog3-4 prog3-5

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
