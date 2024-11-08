#include "arithmetic.idl"

#include "rpcstubhelper.h"

#include <cstdio>
#include <cstring>

using namespace C150NETWORK;

void __add() {
    char doneBuffer[5] = "DONE";

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));    
}

void __divide() {
    char doneBuffer[5] = "DONE";

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));    
}

void __multiply() {
    char doneBuffer[5] = "DONE";

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));    
}

void __subtract() {
    char doneBuffer[5] = "DONE";

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));    
}

void dispatchFunction() {
    int fNameLen;
    RPCSTUBSOCKET->read((char *) &fNameLen, sizeof(fNameLen));

    char functionNameBuffer[fNameLen + 1];

    RPCSTUBSOCKET->read(functionNameBuffer, fNameLen);
    functionNameBuffer[fNameLen] = '\0';

    if (!RPCSTUBSOCKET-> eof()) {
        if (strcmp(functionNameBuffer, "subtract") == 0) {
            __subtract();
        } else if (strcmp(functionNameBuffer, "multiply") == 0) {
            __multiply();
        } else if (strcmp(functionNameBuffer, "divide") == 0) {
            __divide();
        } else if (strcmp(functionNameBuffer, "add") == 0) {
            __add();
        } else {
            throw C150Exception("received above function name\n");
        }
    }
}
