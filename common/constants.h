#ifndef IMPORTED_CONSTANTS_H
#define IMPORTED_CONSTANTS_H

#define SERVER_HOST "localhost"
#define SERVER_PORT 1998

#define MAX_MSG_LEN 1024
#define MAX_USERNAME_LEN 100
#define PACKET_LEN 1124 // Important: must be = MAX_MSG_LEN + MAX_USERNAME_LEN
#define PACKET_FORMAT "%1024s%100s"

#endif