#Compilation options
CC=gcc
CFLAGS=-Wall -g -std=c11 -pthread -c
BINFLAGS=-Wall -g -pthread

#Directories
PROJDIR := $(realpath $(CURDIR)/..)
SRCDIR := $(PROJDIR)/src/
BUILDDIR := $(PROJDIR)/build
BINDIR := .$(PROJDIR)/bin/


TRGT=aparser

OBJ=aparser.o dialogue.o seval.o fileio.o
DEPS=aparser.h

#	  Learned new make features: 
#     $@ resolves to target 
#	  $< resolves to first dependency 
#     $^ resolves to all dependency 

all: $(TRGT)

$(TRGT): $(OBJ)
	$(CC) $(BINFLAGS) -o $@ $^

# aparser.o: aparser.c $(HDR)
# 	$(CC) $(CFLAGS) $< -o $@

# dialogue.o: dialogue.c $(HDR)
# 	$(CC) $(CFLAGS) $< -o $@

# seval.o: seval.c $(HDR)
# 	$(CC) $(CFLAGS) $< -o $@

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

run:
	./aparser

clean:
	rm -f $(TRGT) $(OBJ)

