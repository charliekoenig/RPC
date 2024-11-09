#include "testarray1.idl"

#include "rpcstubhelper.h"

#include <cstdio>
#include <cstring>
#include <vector>

using namespace C150NETWORK;

string getStringFromStream();

void __sqrt() {
    char doneBuffer[5] = "DONE";

    int x[24];
    for (int i = 0; i < 24; i++) { 
        int v1 = stoi(getStringFromStream());
        x[i] = v1;
    }
    int y[24];
    for (int i = 0; i < 24; i++) { 
        int v1 = stoi(getStringFromStream());
        y[i] = v1;
    }
    int retVal = sqrt(x, y);
    string retValStringRep = to_string(retVal);
    RPCSTUBSOCKET->write(retValStringRep.c_str(), retValStringRep.length() + 1);

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));    
}

void dispatchFunction() {
    string functionName = getStringFromStream();

    if (!RPCSTUBSOCKET-> eof()) {
        if (functionName == "sqrt") {
            __sqrt();
        } else {
            throw C150Exception("received above function name\n");
        }
    }
}

string getStringFromStream() {
    char bufp = '\0';

    vector<char> stringRead;

    int readlen = 1;

    while (readlen == 1) { 
        readlen = RPCSTUBSOCKET-> read(&bufp, 1);
        stringRead.push_back(bufp);
        if (bufp == '\0') {
            break;
        }
    }
    return stringRead.data();

}
