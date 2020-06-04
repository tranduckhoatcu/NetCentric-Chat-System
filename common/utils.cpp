#ifndef IMPORTED_UTILS_CPP
#define IMPORTED_UTILS_CPP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"

char* readLine(int maxLen = MAX_MSG_LEN) {
    char* mem = (char*)malloc(sizeof(char)*MAX_MSG_LEN); // contains input data
    fgets(mem, maxLen, stdin); // read maxLen bytes from stdin
    mem[strlen(mem)-1] = '\0'; // pop out \n character at the end of string
    return mem;
}

#endif