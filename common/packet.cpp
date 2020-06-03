#include "packet.h"
#include <stdio.h>
#include <string.h>

char* composeMsgPacket(char* msg, char* username) {
    char* packet = (char*)malloc(sizeof(char)*PACKET_LEN);
    sprintf(packet, "%s: %s", username, msg);
    return packet;
}

MessagePacket::MessagePacket(char* _msg, char* _username) {
    strcpy(msg, _msg);
    strcpy(username, _username);
    char _packet[PACKET_LEN];
    sprintf(_packet, PACKET_FORMAT, _msg, _username);
    strcpy(packet, _packet);
};

MessagePacket::MessagePacket(char rawData[PACKET_LEN]) {
    strcpy(packet, rawData);
    sscanf(rawData, PACKET_FORMAT, msg, username);
};