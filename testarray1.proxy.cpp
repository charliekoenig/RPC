#include "rpcproxyhelper.h"
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

#include "testarray1.idl"
#include "c150grading.h"

using namespace C150NETWORK;

string getStringFromStream();


int sqrt (int x[24], int y[24]) { 
    RPCPROXYSOCKET->write("sqrt", strlen("sqrt") + 1);
    *GRADING << "Invoking function sqrt remotely - message: \"sqrt\", length: " << strlen("sqrt") + 1 << endl;
    *GRADING << "Serializing parameter x"<< endl;
    
    for (int i0 = 0; i0 < 24; i0++) { 
        string xi0StringRep = to_string(x[i0]);
        *GRADING << "Converting " << x[i0] << " of type int to string" << endl;

        RPCPROXYSOCKET->write(xi0StringRep.c_str(), xi0StringRep.length() + 1);
        *GRADING << "Sending value of x[" << i0 << "] in string form - message: \"" << x[i0] << "\", length: " << xi0StringRep.length() + 1 << endl;

    }


    *GRADING << "Serializing parameter y"<< endl;
    
    for (int i0 = 0; i0 < 24; i0++) { 
        string yi0StringRep = to_string(y[i0]);
        *GRADING << "Converting " << y[i0] << " of type int to string" << endl;

        RPCPROXYSOCKET->write(yi0StringRep.c_str(), yi0StringRep.length() + 1);
        *GRADING << "Sending value of y[" << i0 << "] in string form - message: \"" << y[i0] << "\", length: " << yi0StringRep.length() + 1 << endl;

    }


    int retVal = stoi(getStringFromStream());
    *GRADING << "Received value " << retVal << " (of type int in string form) for retVal" << endl;

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
