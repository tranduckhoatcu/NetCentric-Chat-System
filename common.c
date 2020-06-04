#include <stdio.h>

#define MAX_CLIENTS 100
#define BUFFER_SZ 2048
#define LENGTH 2048

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 1998

#define MAX_MSG_LEN 2048
#define MAX_USERNAME_LEN 32
#define MIN_USERNAME_LEN 2
#define PACKET_LEN MAX_MSG_LEN + MAX_USERNAME_LEN

void customPrintStr() {
	printf("%s", "> ");
	fflush(stdout);
}

void trimStrLeft(char *arr, int length) {
	for (int i = 0; i < length; i++) { // trim \n
		if (arr[i] == '\n') {
			arr[i] = '\0';
			break;
		}
	}
}