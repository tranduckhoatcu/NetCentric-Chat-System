#include <iostream>
#include <map>
#include <stdio.h>
#include <ctime>
#include "../common/constants.h"

using namespace std;

map<string, int> usersLastSeenMap;

bool checkValidUsername(string username) {
    if (usersLastSeenMap.find(username) == usersLastSeenMap.end()) // does not exist
        return false;
    else {
        int userAge = time(nullptr) - usersLastSeenMap[username];
        return userAge <= USER_MAX_AGE; // return false if user not responding too long
    }
}

void updateUserLastSeen(string username) {
    usersLastSeenMap[username] = time(nullptr);
}

int main() {
    usersLastSeenMap["A"] = time(nullptr);
    usersLastSeenMap["B"] = time(nullptr);
    
    cout << usersLastSeenMap["A"] << endl;
    cout << usersLastSeenMap["B"] << endl;
    // Server main code here
}