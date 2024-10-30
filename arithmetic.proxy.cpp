#include "arithmetic.idl"

#include "rpcproxyhelper.h"

#include <cstdio>
#include <cstring>

using namespace C150NETWORK;

int add(int x, int y) {
        int fNameLen = strlen("add");
        RPCPROXYSOCKET->write((const char *) &fNameLen, sizeof(fNameLen));
        RPCPROXYSOCKET->write("add", strlen("add")); // write function name including null
        
        RPCPROXYSOCKET->write((const char *) &x, sizeof(x));
        RPCPROXYSOCKET->write((const char *) &y, sizeof(y));

        int retVal;
        RPCPROXYSOCKET->read((char *) &retVal, sizeof(retVal));

        char readBuffer[4];
        RPCPROXYSOCKET->read(readBuffer, 4);
        if (strncmp(readBuffer, "DONE", 4) != 0) {
                throw C150Exception("arithmetic.proxy: add(int x, int y) received invalid response from the server");
        }

        return retVal;
}

int subtract(int x, int y) {
        printf("oops: %d and %d\n", x, y);
        return 0;
}
int multiply(int x, int y) {
        printf("oops: %d and %d\n", x, y);
        return 0;
}
int divide(int x, int y) {
        printf("oops: %d and %d\n", x, y);
        return 0;
}