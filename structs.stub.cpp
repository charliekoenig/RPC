#include "structs.idl"

#include "rpcstubhelper.h"

#include <cstdio>
#include <cstring>
#include <vector>

using namespace C150NETWORK;

string getStringFromStream();

void __oldestAge() {
    char doneBuffer[5] = "DONE";

    StructWithArrays x[10];
    for (int i0 = 0; i0 < 10; i0++) { 
        x[i0].aNumber = stoi(getStringFromStream());
        for (int i1 = 0; i1 < 10; i1++) { 
            x[i0].people[i1].age = stoi(getStringFromStream());
        }

    }

    int retVal = oldestAge(x);
    string retValStringRep = to_string(retVal);
    RPCSTUBSOCKET->write(retValStringRep.c_str(), retValStringRep.length() + 1);
    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));    
}

void dispatchFunction() {
    string functionName = getStringFromStream();

    if (!RPCSTUBSOCKET-> eof()) {
        if (functionName == "oldestAge") {
            __oldestAge();
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
