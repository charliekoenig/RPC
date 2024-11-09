#include "arithmetic.idl"

#include "rpcproxyhelper.h"

#include <cstdio>
#include <cstring>

using namespace C150NETWORK;

string getStringFromStream();

int add(int x, int y) {
    RPCPROXYSOCKET->write("add", strlen("add") + 1);

    string xStringRep = to_string(x);
    RPCPROXYSOCKET->write(xStringRep.c_str(), xStringRep.length() + 1);

    string yStringRep = to_string(y);
    RPCPROXYSOCKET->write(yStringRep.c_str(), yStringRep.length() + 1);

    int retVal = stoi(getStringFromStream());
    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    return retVal;
}

int divide(int x, int y) {
    RPCPROXYSOCKET->write("divide", strlen("divide") + 1);

    string xStringRep = to_string(x);
    RPCPROXYSOCKET->write(xStringRep.c_str(), xStringRep.length() + 1);

    string yStringRep = to_string(y);
    RPCPROXYSOCKET->write(yStringRep.c_str(), yStringRep.length() + 1);

    int retVal = stoi(getStringFromStream());
    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    return retVal;
}

int multiply(int x, int y) {
    RPCPROXYSOCKET->write("multiply", strlen("multiply") + 1);

    string xStringRep = to_string(x);
    RPCPROXYSOCKET->write(xStringRep.c_str(), xStringRep.length() + 1);

    string yStringRep = to_string(y);
    RPCPROXYSOCKET->write(yStringRep.c_str(), yStringRep.length() + 1);

    int retVal = stoi(getStringFromStream());
    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    return retVal;
}

int subtract(int x, int y) {
    RPCPROXYSOCKET->write("subtract", strlen("subtract") + 1);

    string xStringRep = to_string(x);
    RPCPROXYSOCKET->write(xStringRep.c_str(), xStringRep.length() + 1);

    string yStringRep = to_string(y);
    RPCPROXYSOCKET->write(yStringRep.c_str(), yStringRep.length() + 1);

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
