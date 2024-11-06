#include "simplefunction.idl"

#include "rpcproxyhelper.h"

#include <cstdio>
#include <cstring>

using namespace C150NETWORK;

void func1() {
    int fNameLen = strlen("func1");
    RPCPROXYSOCKET->write((const char *) &fNameLen, sizeof(fNameLen));
    RPCPROXYSOCKET->write("func1", strlen("func1"));

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
}

void func2() {
    int fNameLen = strlen("func2");
    RPCPROXYSOCKET->write((const char *) &fNameLen, sizeof(fNameLen));
    RPCPROXYSOCKET->write("func2", strlen("func2"));

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
}

void func3() {
    int fNameLen = strlen("func3");
    RPCPROXYSOCKET->write((const char *) &fNameLen, sizeof(fNameLen));
    RPCPROXYSOCKET->write("func3", strlen("func3"));

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
}

