#include "rpcproxyhelper.h"
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

#include "floatarithmetic.idl"
#include "c150grading.h"

using namespace C150NETWORK;

string getStringFromStream();


float add (float x, float y) { 
    RPCPROXYSOCKET->write("add", strlen("add") + 1);
    *GRADING << "Invoking function add remotely - message: \"add\", length: " << strlen("add") + 1 << endl;
    *GRADING << "Serializing parameter x"<< endl;
    string xStringRep = to_string(x);
    *GRADING << "Converting " << x << " of type float to string" << endl;

    RPCPROXYSOCKET->write(xStringRep.c_str(), xStringRep.length() + 1);
    *GRADING << "Sending value of x in string form - message: \"" << x << "\", length: " << xStringRep.length() + 1 << endl;

    *GRADING << "Serializing parameter y"<< endl;
    string yStringRep = to_string(y);
    *GRADING << "Converting " << y << " of type float to string" << endl;

    RPCPROXYSOCKET->write(yStringRep.c_str(), yStringRep.length() + 1);
    *GRADING << "Sending value of y in string form - message: \"" << y << "\", length: " << yStringRep.length() + 1 << endl;

    float retVal = stof(getStringFromStream());
    *GRADING << "Received value " << retVal << " (of type float in string form) for retVal" << endl;

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
    
    return retVal;
}

float divide (float x, float y) { 
    RPCPROXYSOCKET->write("divide", strlen("divide") + 1);
    *GRADING << "Invoking function divide remotely - message: \"divide\", length: " << strlen("divide") + 1 << endl;
    *GRADING << "Serializing parameter x"<< endl;
    string xStringRep = to_string(x);
    *GRADING << "Converting " << x << " of type float to string" << endl;

    RPCPROXYSOCKET->write(xStringRep.c_str(), xStringRep.length() + 1);
    *GRADING << "Sending value of x in string form - message: \"" << x << "\", length: " << xStringRep.length() + 1 << endl;

    *GRADING << "Serializing parameter y"<< endl;
    string yStringRep = to_string(y);
    *GRADING << "Converting " << y << " of type float to string" << endl;

    RPCPROXYSOCKET->write(yStringRep.c_str(), yStringRep.length() + 1);
    *GRADING << "Sending value of y in string form - message: \"" << y << "\", length: " << yStringRep.length() + 1 << endl;

    float retVal = stof(getStringFromStream());
    *GRADING << "Received value " << retVal << " (of type float in string form) for retVal" << endl;

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
    
    return retVal;
}

float multiply (float x, float y) { 
    RPCPROXYSOCKET->write("multiply", strlen("multiply") + 1);
    *GRADING << "Invoking function multiply remotely - message: \"multiply\", length: " << strlen("multiply") + 1 << endl;
    *GRADING << "Serializing parameter x"<< endl;
    string xStringRep = to_string(x);
    *GRADING << "Converting " << x << " of type float to string" << endl;

    RPCPROXYSOCKET->write(xStringRep.c_str(), xStringRep.length() + 1);
    *GRADING << "Sending value of x in string form - message: \"" << x << "\", length: " << xStringRep.length() + 1 << endl;

    *GRADING << "Serializing parameter y"<< endl;
    string yStringRep = to_string(y);
    *GRADING << "Converting " << y << " of type float to string" << endl;

    RPCPROXYSOCKET->write(yStringRep.c_str(), yStringRep.length() + 1);
    *GRADING << "Sending value of y in string form - message: \"" << y << "\", length: " << yStringRep.length() + 1 << endl;

    float retVal = stof(getStringFromStream());
    *GRADING << "Received value " << retVal << " (of type float in string form) for retVal" << endl;

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
    
    return retVal;
}

float subtract (float x, float y) { 
    RPCPROXYSOCKET->write("subtract", strlen("subtract") + 1);
    *GRADING << "Invoking function subtract remotely - message: \"subtract\", length: " << strlen("subtract") + 1 << endl;
    *GRADING << "Serializing parameter x"<< endl;
    string xStringRep = to_string(x);
    *GRADING << "Converting " << x << " of type float to string" << endl;

    RPCPROXYSOCKET->write(xStringRep.c_str(), xStringRep.length() + 1);
    *GRADING << "Sending value of x in string form - message: \"" << x << "\", length: " << xStringRep.length() + 1 << endl;

    *GRADING << "Serializing parameter y"<< endl;
    string yStringRep = to_string(y);
    *GRADING << "Converting " << y << " of type float to string" << endl;

    RPCPROXYSOCKET->write(yStringRep.c_str(), yStringRep.length() + 1);
    *GRADING << "Sending value of y in string form - message: \"" << y << "\", length: " << yStringRep.length() + 1 << endl;

    float retVal = stof(getStringFromStream());
    *GRADING << "Received value " << retVal << " (of type float in string form) for retVal" << endl;

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
    
    return retVal;
}

string getStringFromStream () { 
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
