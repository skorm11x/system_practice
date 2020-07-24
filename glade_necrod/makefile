#Continuing practice with makefiles from scratch
#Remember: variables can only be strings
CC=gcc

all: necrod child

necrod: necrod.c
	cc -std=c11 -pedantic necrod.c -lm `pkg-config --cflags --libs gtk+-3.0` -export-dynamic -o necrod

child: child.c
	cc -std=c11 -pedantic child.c -o child


clean:
	rm -f necrod child