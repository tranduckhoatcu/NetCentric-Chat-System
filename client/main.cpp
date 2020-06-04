#include <stdio.h>
#include "../common/constants.h"
#include "../common/packet.cpp"
#include "../common/utils.cpp"
#include <string.h>

int main() {
    printf("Hello World\n");
    char* iMsg = readLine(MAX_MSG_LEN);
    char* iUsername = readLine(MAX_USERNAME_LEN);
   
    char* str2sent = composeMsgPacket(iMsg, iUsername);
    printf(str2sent);

    // MessagePacket msgPacket = MessagePacket(iMsg, iUsername);
    // printf("%s\n", msgPacket.getMsg());
    // printf("%s\n", msgPacket.getUsername());
    // char* v = (char*)malloc(sizeof(char)*PACKET_LEN);
    // strcpy(v, msgPacket.getPacket());
    // MessagePacket msg2 = MessagePacket(v);
    // printf("%s\n", msg2.getMsg());
    // printf("%s\n", msg2.getUsername());

    // Client main code here
}