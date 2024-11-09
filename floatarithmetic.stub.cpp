#include "floatarithmetic.idl"

#include "rpcstubhelper.h"

#include <cstdio>
#include <cstring>
#include <vector>

using namespace C150NETWORK;

string getStringFromStream();

void __add() {
    char doneBuffer[5] = "DONE";

float x = stof(getStringFromStream());
float y = stof(getStringFromStream());
    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));    
}

void __divide() {
    char doneBuffer[5] = "DONE";

float x = stof(getStringFromStream());
float y = stof(getStringFromStream());
    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));    
}

void __multiply() {
    char doneBuffer[5] = "DONE";

float x = stof(getStringFromStream());
float y = stof(getStringFromStream());
    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));    
}

void __subtract() {
    char doneBuffer[5] = "DONE";

float x = stof(getStringFromStream());
float y = stof(getStringFromStream());
    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));    
}

void dispatchFunction() {
    string functionName = getStringFromStream();

    if (!RPCSTUBSOCKET-> eof()) {
        if (functionName == "subtract") {
            __subtract();
        } else if (functionName == "multiply") {
            __multiply();
        } else if (functionName == "divide") {
            __divide();
        } else if (functionName == "add") {
            __add();
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
