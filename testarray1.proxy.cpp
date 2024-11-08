#include "testarray1.idl"

#include "rpcproxyhelper.h"

#include <cstdio>
#include <cstring>

using namespace C150NETWORK;

int sqrt(__int[24] x, __int[24] y) {
    int fNameLen = strlen("sqrt");
    RPCPROXYSOCKET->write((const char *) &fNameLen, sizeof(fNameLen));
    RPCPROXYSOCKET->write("sqrt", strlen("sqrt"));

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
}

