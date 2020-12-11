#define varibles for program compilation process
cc=gcc
flags=-Wall -g -pthread

all: download_curl
# -lcurl necessary to compile lcurl static, -lcrypto & -lssl needed for openssl
download_curl: download_curl.c
	$(cc) $(flags) download_curl.c -o download_curl -lcurl -lcrypto -lssl

clean:
	rm -rf download_curl result.html