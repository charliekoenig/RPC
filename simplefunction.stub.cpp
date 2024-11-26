#include "rpcstubhelper.h"
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

#include "simplefunction.idl"
#include "c150grading.h"

using namespace C150NETWORK;

string getStringFromStream();


void __func1 () { 
    char doneBuffer[5] = "DONE";
    *GRADING << "Function func1 invoked locally" << endl;
    func1();
    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function func1 invocation done"<< endl;
}

void __func2 () { 
    char doneBuffer[5] = "DONE";
    *GRADING << "Function func2 invoked locally" << endl;
    func2();
    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function func2 invocation done"<< endl;
}

void __func3 () { 
    char doneBuffer[5] = "DONE";
    *GRADING << "Function func3 invoked locally" << endl;
    func3();
    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function func3 invocation done"<< endl;
}

void dispatchFunction () { 
    string functionName = getStringFromStream();
    if (!RPCSTUBSOCKET-> eof()) {
        if (functionName == "func3") {
            __func3();
        } else if (functionName == "func2") {
            __func2();
        } else if (functionName == "func1") {
            __func1();
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
