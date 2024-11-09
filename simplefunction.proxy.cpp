#include "simplefunction.idl"

#include "rpcproxyhelper.h"

#include <cstdio>
#include <cstring>

using namespace C150NETWORK;

string getStringFromStream();

void func1() {
    RPCPROXYSOCKET->write("func1", strlen("func1") + 1);

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
}

void func2() {
    RPCPROXYSOCKET->write("func2", strlen("func2") + 1);

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
}

void func3() {
    RPCPROXYSOCKET->write("func3", strlen("func3") + 1);

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
}

