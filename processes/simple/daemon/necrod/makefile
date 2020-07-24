#Continuing practice with makefiles from scratch
#Remember: variables can only be strings
CC=gcc

all: necrod child

necrod: necrod.o
	cc necrod.o -o necrod

necrod.o: necrod.c
	cc -c necrod.c	-o necrod.o

child: child.o
	cc child.o -o child

child.o: child.c
	cc -c child.c -o child.o

clean:
	rm -f necrod necrod.o child child.o