#include "floatarithmetic.idl"

#include "rpcproxyhelper.h"

#include <cstdio>
#include <cstring>

using namespace C150NETWORK;

float add(float x, float y) {
    RPCPROXYSOCKET->write("add", strlen("add") + 1);

string xStringRep = to_string(x);
RPCPROXYSOCKET->write(xStringRep.c_str(), xStringRep.length() + 1);

string yStringRep = to_string(y);
RPCPROXYSOCKET->write(yStringRep.c_str(), yStringRep.length() + 1);

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
}

float divide(float x, float y) {
    RPCPROXYSOCKET->write("divide", strlen("divide") + 1);

string xStringRep = to_string(x);
RPCPROXYSOCKET->write(xStringRep.c_str(), xStringRep.length() + 1);

string yStringRep = to_string(y);
RPCPROXYSOCKET->write(yStringRep.c_str(), yStringRep.length() + 1);

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
}

float multiply(float x, float y) {
    RPCPROXYSOCKET->write("multiply", strlen("multiply") + 1);

string xStringRep = to_string(x);
RPCPROXYSOCKET->write(xStringRep.c_str(), xStringRep.length() + 1);

string yStringRep = to_string(y);
RPCPROXYSOCKET->write(yStringRep.c_str(), yStringRep.length() + 1);

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
}

float subtract(float x, float y) {
    RPCPROXYSOCKET->write("subtract", strlen("subtract") + 1);

string xStringRep = to_string(x);
RPCPROXYSOCKET->write(xStringRep.c_str(), xStringRep.length() + 1);

string yStringRep = to_string(y);
RPCPROXYSOCKET->write(yStringRep.c_str(), yStringRep.length() + 1);

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
}

