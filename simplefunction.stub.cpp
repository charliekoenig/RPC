#include "simplefunction.idl"

#include "rpcstubhelper.h"

#include <cstdio>
#include <cstring>

using namespace C150NETWORK;

void __func1() {
    char doneBuffer[5] = "DONE";

    func1();

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
}

void __func2() {
    char doneBuffer[5] = "DONE";

    func2();

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
}

void __func3() {
    char doneBuffer[5] = "DONE";

    func3();

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
}

void dispatchFunction() {
    int fNameLen;
    RPCSTUBSOCKET->read((char *) &fNameLen, sizeof(fNameLen));

    char functionNameBuffer[fNameLen + 1];

    RPCSTUBSOCKET->read(functionNameBuffer, fNameLen);
    functionNameBuffer[fNameLen] = '\0';

    if (!RPCSTUBSOCKET-> eof()) {
        if (strcmp(functionNameBuffer, "func3") == 0) {
            __func3();
        } else if (strcmp(functionNameBuffer, "func2") == 0) {
            __func2();
        } else if (strcmp(functionNameBuffer, "func1") == 0) {
            __func1();
        } else {
            throw C150Exception("received above function name\n");
        }
    }
}
