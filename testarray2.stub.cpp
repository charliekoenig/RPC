#include "rpcstubhelper.h"
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

#include "testarray2.idl"
#include "c150grading.h"

using namespace C150NETWORK;

string getStringFromStream();


void __sqrt () { 
    char doneBuffer[5] = "DONE";
    int x[24];
    
    for (int i0 = 0; i0 < 24; i0++) { 
        x[i0] = stoi(getStringFromStream());
        *GRADING << "Received value " << x[i0] << " (of type int in string form) for x[" << i0 << "]" << endl;

    }


    int y[24][15];
    
    for (int i0 = 0; i0 < 24; i0++) { 
        
        for (int i1 = 0; i1 < 15; i1++) { 
            y[i0][i1] = stoi(getStringFromStream());
            *GRADING << "Received value " << y[i0][i1] << " (of type int in string form) for y[" << i0 << "][" << i1 << "]" << endl;

        }

    }


    int z[24][15];
    
    for (int i0 = 0; i0 < 24; i0++) { 
        
        for (int i1 = 0; i1 < 15; i1++) { 
            z[i0][i1] = stoi(getStringFromStream());
            *GRADING << "Received value " << z[i0][i1] << " (of type int in string form) for z[" << i0 << "][" << i1 << "]" << endl;

        }

    }


    *GRADING << "Function sqrt invoked locally" << endl;
    int retVal = sqrt(x, y, z);
    string retValStringRep = to_string(retVal);
    *GRADING << "Converting " << retVal << " of type int to string" << endl;

    RPCSTUBSOCKET->write(retValStringRep.c_str(), retValStringRep.length() + 1);
    *GRADING << "Sending value of retVal in string form - message: \"" << retVal << "\", length: " << retValStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function sqrt invocation done"<< endl;
}

void dispatchFunction () { 
    string functionName = getStringFromStream();
    if (!RPCSTUBSOCKET-> eof()) {
        if (functionName == "sqrt") {
            __sqrt();
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
