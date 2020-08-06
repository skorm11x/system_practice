#Makefile for compiling ptr c problems focused on embedded
cc=gcc
p_flags=-Wall -g -pthread -std=c11
flags=-Wall -g -std=c11

all: ptr1 ptr2 ptr3

ptr1: ptr1.c
	$(cc) $(flags) ptr1.c -o ptr1

ptr2: ptr2.c
	$(cc) $(flags) ptr2.c -o ptr2

ptr3: ptr3.c ptr3.h
	$(cc) $(p_flags) ptr3.c -o ptr3

clean:
	rm -f ptr1 ptr2 ptr3