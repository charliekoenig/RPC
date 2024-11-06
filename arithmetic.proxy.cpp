#include "arithmetic.idl"

#include "rpcproxyhelper.h"

#include <cstdio>
#include <cstring>

using namespace C150NETWORK;

int add(int x, int y) {
    int fNameLen = strlen("add");
    RPCPROXYSOCKET->write((const char *) &fNameLen, sizeof(fNameLen));
    RPCPROXYSOCKET->write("add", strlen("add"));

    RPCPROXYSOCKET->write((const char *) &x, sizeof(x));

    RPCPROXYSOCKET->write((const char *) &y, sizeof(y));

    int retVal;
    RPCPROXYSOCKET->read((char *) &retVal, sizeof(retVal));

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }    return retVal;
}

int divide(int x, int y) {
    int fNameLen = strlen("divide");
    RPCPROXYSOCKET->write((const char *) &fNameLen, sizeof(fNameLen));
    RPCPROXYSOCKET->write("divide", strlen("divide"));

    RPCPROXYSOCKET->write((const char *) &x, sizeof(x));

    RPCPROXYSOCKET->write((const char *) &y, sizeof(y));

    int retVal;
    RPCPROXYSOCKET->read((char *) &retVal, sizeof(retVal));

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }    return retVal;
}

int multiply(int x, int y) {
    int fNameLen = strlen("multiply");
    RPCPROXYSOCKET->write((const char *) &fNameLen, sizeof(fNameLen));
    RPCPROXYSOCKET->write("multiply", strlen("multiply"));

    RPCPROXYSOCKET->write((const char *) &x, sizeof(x));

    RPCPROXYSOCKET->write((const char *) &y, sizeof(y));

    int retVal;
    RPCPROXYSOCKET->read((char *) &retVal, sizeof(retVal));

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }    return retVal;
}

int subtract(int x, int y) {
    int fNameLen = strlen("subtract");
    RPCPROXYSOCKET->write((const char *) &fNameLen, sizeof(fNameLen));
    RPCPROXYSOCKET->write("subtract", strlen("subtract"));

    RPCPROXYSOCKET->write((const char *) &x, sizeof(x));

    RPCPROXYSOCKET->write((const char *) &y, sizeof(y));

    int retVal;
    RPCPROXYSOCKET->read((char *) &retVal, sizeof(retVal));

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }    return retVal;
}

