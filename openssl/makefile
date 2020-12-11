cc=gcc
flags=-Wall -g -pthread

all: Client Server

Client: Client.c
	$(cc) -Wall -o client  Client.c -L/usr/lib -lssl -lcrypto

Server: Server.c
	$(cc) -Wall -o server Server.c -L/usr/lib -lssl -lcrypto

clean:
	rm -rf client server