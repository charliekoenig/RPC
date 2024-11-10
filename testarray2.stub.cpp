#include "testarray2.idl"

#include "rpcstubhelper.h"

#include <cstdio>
#include <cstring>
#include <vector>

using namespace C150NETWORK;

string getStringFromStream();

void __sqrt() {
    char doneBuffer[5] = "DONE";

    int x[24];
    for (int i0 = 0; i0 < 24; i++) { 
        x[i0] = stoi(getStringFromStream());
    }

    int y[24][15];
    for (int i0 = 0; i0 < 24; i++) { 
        for (int i1 = 0; i1 < 15; i++) { 
            y[i0][i1] = stoi(getStringFromStream());
        }
    }

    int z[24][15];
    for (int i0 = 0; i0 < 24; i++) { 
        for (int i1 = 0; i1 < 15; i++) { 
            z[i0][i1] = stoi(getStringFromStream());
        }
    }

    int retVal = sqrt(x, y, z);
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
