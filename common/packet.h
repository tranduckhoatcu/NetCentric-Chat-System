#ifndef IMPORTED_PACKET_H
#define IMPORTED_PACKET_H

#include "constants.h"
#include <stdlib.h>

char* composeMsgPacket(char* msg, char* username);

class MessagePacket {
    private:
        char* msg = (char*)malloc(sizeof(char)*MAX_MSG_LEN);
        char* username = (char*)malloc(sizeof(char)*MAX_USERNAME_LEN);
        char* packet = (char*)malloc(sizeof(char)*PACKET_LEN);
    public:
        MessagePacket(char msg[MAX_MSG_LEN], char username[MAX_USERNAME_LEN]);
        MessagePacket(char rawData[PACKET_LEN]);

        char* getMsg() { return msg; };
        char* getUsername() { return username; }
        char* getPacket() { return packet; }
};

#endif