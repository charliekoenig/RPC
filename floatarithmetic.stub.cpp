#include "rpcstubhelper.h"
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

#include "floatarithmetic.idl"
#include "c150grading.h"

using namespace C150NETWORK;

string getStringFromStream();


void __add () { 
    char doneBuffer[5] = "DONE";
    float x = stof(getStringFromStream());
    *GRADING << "Received value " << x << " (of type float in string form) for x" << endl;

    float y = stof(getStringFromStream());
    *GRADING << "Received value " << y << " (of type float in string form) for y" << endl;

    *GRADING << "Function add invoked locally" << endl;
    float retVal = add(x, y);
    string retValStringRep = to_string(retVal);
    *GRADING << "Converting " << retVal << " of type float to string" << endl;

    RPCSTUBSOCKET->write(retValStringRep.c_str(), retValStringRep.length() + 1);
    *GRADING << "Sending value of retVal in string form - message: \"" << retVal << "\", length: " << retValStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function add invocation done"<< endl;
}

void __divide () { 
    char doneBuffer[5] = "DONE";
    float x = stof(getStringFromStream());
    *GRADING << "Received value " << x << " (of type float in string form) for x" << endl;

    float y = stof(getStringFromStream());
    *GRADING << "Received value " << y << " (of type float in string form) for y" << endl;

    *GRADING << "Function divide invoked locally" << endl;
    float retVal = divide(x, y);
    string retValStringRep = to_string(retVal);
    *GRADING << "Converting " << retVal << " of type float to string" << endl;

    RPCSTUBSOCKET->write(retValStringRep.c_str(), retValStringRep.length() + 1);
    *GRADING << "Sending value of retVal in string form - message: \"" << retVal << "\", length: " << retValStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function divide invocation done"<< endl;
}

void __multiply () { 
    char doneBuffer[5] = "DONE";
    float x = stof(getStringFromStream());
    *GRADING << "Received value " << x << " (of type float in string form) for x" << endl;

    float y = stof(getStringFromStream());
    *GRADING << "Received value " << y << " (of type float in string form) for y" << endl;

    *GRADING << "Function multiply invoked locally" << endl;
    float retVal = multiply(x, y);
    string retValStringRep = to_string(retVal);
    *GRADING << "Converting " << retVal << " of type float to string" << endl;

    RPCSTUBSOCKET->write(retValStringRep.c_str(), retValStringRep.length() + 1);
    *GRADING << "Sending value of retVal in string form - message: \"" << retVal << "\", length: " << retValStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function multiply invocation done"<< endl;
}

void __subtract () { 
    char doneBuffer[5] = "DONE";
    float x = stof(getStringFromStream());
    *GRADING << "Received value " << x << " (of type float in string form) for x" << endl;

    float y = stof(getStringFromStream());
    *GRADING << "Received value " << y << " (of type float in string form) for y" << endl;

    *GRADING << "Function subtract invoked locally" << endl;
    float retVal = subtract(x, y);
    string retValStringRep = to_string(retVal);
    *GRADING << "Converting " << retVal << " of type float to string" << endl;

    RPCSTUBSOCKET->write(retValStringRep.c_str(), retValStringRep.length() + 1);
    *GRADING << "Sending value of retVal in string form - message: \"" << retVal << "\", length: " << retValStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function subtract invocation done"<< endl;
}

void dispatchFunction () { 
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
            RPCSTUBSOCKET->write("BAD", strlen("BAD") + 1);
        }
    }
}

string getStringFromStream () { 
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
