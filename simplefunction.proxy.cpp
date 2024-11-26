#include "rpcproxyhelper.h"
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

#include "simplefunction.idl"
#include "c150grading.h"

using namespace C150NETWORK;

string getStringFromStream();


void func1 () { 
    RPCPROXYSOCKET->write("func1", strlen("func1") + 1);
    *GRADING << "Invoking function func1 remotely - message: \"func1\", length: " << strlen("func1") + 1 << endl;
    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
}

void func2 () { 
    RPCPROXYSOCKET->write("func2", strlen("func2") + 1);
    *GRADING << "Invoking function func2 remotely - message: \"func2\", length: " << strlen("func2") + 1 << endl;
    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
}

void func3 () { 
    RPCPROXYSOCKET->write("func3", strlen("func3") + 1);
    *GRADING << "Invoking function func3 remotely - message: \"func3\", length: " << strlen("func3") + 1 << endl;
    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
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
