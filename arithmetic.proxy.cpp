#include "arithmetic.idl"

#include "rpcproxyhelper.h"

#include <cstdio>
#include <cstring>

using namespace C150NETWORK;

int add(int x, int y) {
    int fNameLen = strlen("add");
    RPCPROXYSOCKET->write((const char *) &fNameLen, sizeof(fNameLen));
    RPCPROXYSOCKET->write("add", strlen("add"));

string numStringRep = to_string(x);RPCPROXYSOCKET->write(numStringRep.c_str(), numStringRep.length() + 1);

string numStringRep = to_string(y);RPCPROXYSOCKET->write(numStringRep.c_str(), numStringRep.length() + 1);

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
}

int divide(int x, int y) {
    int fNameLen = strlen("divide");
    RPCPROXYSOCKET->write((const char *) &fNameLen, sizeof(fNameLen));
    RPCPROXYSOCKET->write("divide", strlen("divide"));

string numStringRep = to_string(x);RPCPROXYSOCKET->write(numStringRep.c_str(), numStringRep.length() + 1);

string numStringRep = to_string(y);RPCPROXYSOCKET->write(numStringRep.c_str(), numStringRep.length() + 1);

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
}

int multiply(int x, int y) {
    int fNameLen = strlen("multiply");
    RPCPROXYSOCKET->write((const char *) &fNameLen, sizeof(fNameLen));
    RPCPROXYSOCKET->write("multiply", strlen("multiply"));

string numStringRep = to_string(x);RPCPROXYSOCKET->write(numStringRep.c_str(), numStringRep.length() + 1);

string numStringRep = to_string(y);RPCPROXYSOCKET->write(numStringRep.c_str(), numStringRep.length() + 1);

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
}

int subtract(int x, int y) {
    int fNameLen = strlen("subtract");
    RPCPROXYSOCKET->write((const char *) &fNameLen, sizeof(fNameLen));
    RPCPROXYSOCKET->write("subtract", strlen("subtract"));

string numStringRep = to_string(x);RPCPROXYSOCKET->write(numStringRep.c_str(), numStringRep.length() + 1);

string numStringRep = to_string(y);RPCPROXYSOCKET->write(numStringRep.c_str(), numStringRep.length() + 1);

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
}

