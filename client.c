#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include "common.c"

volatile sig_atomic_t flag = 0; // working flag, if 1 then exit program
int sockfd = 0; // Main socket
char username[MAX_USERNAME_LEN];

void catchCtrlCAndExit(int sig) {
	flag = 1;
}

void sendMsgHandler() {
	char message[MAX_MSG_LEN] = {};
	char buffer[MAX_USERNAME_LEN + MAX_USERNAME_LEN] = {};

	while (1) {
		customPrintStr();
		fgets(message, LENGTH, stdin);
		trimStrLeft(message, LENGTH);

		if (strcmp(message, "exit") == 0) // exit app when user input "exit"
			break; 
		else {
			sprintf(buffer, "%s: %s\n", username, message);
			send(sockfd, buffer, strlen(buffer), 0);
		}

		bzero(message, LENGTH);
		bzero(buffer, LENGTH + 32);
	}
	catchCtrlCAndExit(2);
}

void RecvMsgHandler() {
	char message[PACKET_LEN] = {};
	while (1) {
		int receive = recv(sockfd, message, PACKET_LEN, 0);
		if (receive > 0) { // succesfully
			printf("%s", message);
			customPrintStr();
		}
		else if (receive == 0) { // exit when catch error
			break;
		}
		else {
			// -1
		}
		memset(message, 0, sizeof(message));
	}
}

int main(int argc, char **argv) {
	char *ip = SERVER_IP;
	int port = SERVER_PORT;

	signal(SIGINT, catchCtrlCAndExit);

	printf("Enter your username: ");
	fgets(username, 32, stdin);
	trimStrLeft(username, strlen(username));

	if (strlen(username) > MAX_USERNAME_LEN || strlen(username) < MIN_USERNAME_LEN) { // check username length
		printf("Too short or too long uusername.\n");
		return EXIT_FAILURE;
	}

	struct sockaddr_in server_addr;

	/* Socket settings */
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(ip);
	server_addr.sin_port = htons(port);

	// Connect to Server
	int err = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
	if (err == -1) {
		perror("ERROR: can not connect to server\n");
		return EXIT_FAILURE;
	}

	// Send username
	send(sockfd, username, 32, 0);

	printf("NETCENTRIC TCP CHATTING APPLICATION - CLIENT\n");

	pthread_t sendMsgThread;
	if (pthread_create(&sendMsgThread, NULL, (void *)sendMsgHandler, NULL) != 0) {
		perror("ERROR: can not create sending thread\n");
		return EXIT_FAILURE;
	}

	pthread_t recvMsgThread;
	if (pthread_create(&recvMsgThread, NULL, (void *)RecvMsgHandler, NULL) != 0) {
		perror("ERROR: can not create receving thread\n");
		return EXIT_FAILURE;
	}

	while (1){
		if (flag) {
			printf("\nSee u later\n");
			break;
		}
	}

	close(sockfd);

	return EXIT_SUCCESS;
}