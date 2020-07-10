all: parent child

parent: parent.c
	gcc -g parent.c -o parent

child: child.c
	gcc -g child.c -o child

clean:
	rm -f child parent