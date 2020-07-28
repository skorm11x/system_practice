#Makefile for comparing C program standard lib vs. asm for "hello world"
cc=GCC

all: hello hello2

hello2: hello2.o
	$(CC) hello2.o -o hello2

hello2.o: hello.c
	$(CC) -c hello.c -o hello2.o

hello: hello.o
	ld -s hello.o -o hello

hello.o: hello.asm
	nasm -f elf64 hello.asm 

clean:
	rm -f hello.o hello2.o hello hello2