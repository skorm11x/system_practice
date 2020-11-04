#define varibles for program compilation process
cc=gcc
flags=-Wall -g -pthread

all: download_curl

download_curl: download_curl.c
	$(cc) $(flags) download_curl.c -o download_curl -lcurl

clean:
	rm -rf download_curl result.html