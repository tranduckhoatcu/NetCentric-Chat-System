#ifndef IMPORTED_PACKET_CPP
#define IMPORTED_PACKET_CPP

#include "constants.h"
#include <stdio.h>
#include <stdlib.h>

char* composeMsgPacket(char* msg, char* username) {
    char* packet = (char*)malloc(sizeof(char)*PACKET_LEN);
    sprintf(packet, "%s: %s", username, msg);
    return packet;
}

#endif