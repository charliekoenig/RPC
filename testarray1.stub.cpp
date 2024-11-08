#include "testarray1.idl"

#include "rpcstubhelper.h"

#include <cstdio>
#include <cstring>

using namespace C150NETWORK;

void __sqrt() {
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
        if (strcmp(functionNameBuffer, "sqrt") == 0) {
            __sqrt();
        } else {
            throw C150Exception("received above function name\n");
        }
    }
}
