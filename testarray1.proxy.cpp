#include "testarray1.idl"

#include "rpcproxyhelper.h"

#include <cstdio>
#include <cstring>

using namespace C150NETWORK;

string getStringFromStream();

int sqrt(__int[24] x, __int[24] y) {
    RPCPROXYSOCKET->write("sqrt", strlen("sqrt") + 1);



    int retVal = stoi(getStringFromStream());
    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    return retVal;
}

string getStringFromStream() {
    char bufp = '\0';

    vector<char> stringRead;

    int readlen = 1;

    while (readlen == 1) { 
        readlen = RPCPROXYSOCKET-> read(&bufp, 1);
        stringRead.push_back(bufp);
        if (bufp == '\0') {
            break;
        }
    }
    return stringRead.data();

}
