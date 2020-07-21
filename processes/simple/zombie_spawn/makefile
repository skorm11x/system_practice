CC=gcc #CC == compiler option, typically clang, gcc

all: parent child

parent: parent.c
	gcc  parent.c -o necro

child: child.c
	gcc  child.c -o .child

clean:
	rm -f .child necro