#include "simplefunction.idl"

#include "rpcstubhelper.h"

#include <cstdio>
#include <cstring>
#include <vector>

using namespace C150NETWORK;

string getStringFromStream();

void __func1() {
    char doneBuffer[5] = "DONE";

    func1();
    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));    
}

void __func2() {
    char doneBuffer[5] = "DONE";

    func2();
    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));    
}

void __func3() {
    char doneBuffer[5] = "DONE";

    func3();
    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));    
}

void dispatchFunction() {
    string functionName = getStringFromStream();

    if (!RPCSTUBSOCKET-> eof()) {
        if (functionName == "func3") {
            __func3();
        } else if (functionName == "func2") {
            __func2();
        } else if (functionName == "func1") {
            __func1();
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
