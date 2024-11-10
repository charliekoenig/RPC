#include "testarray2.idl"

#include "rpcproxyhelper.h"

#include <cstdio>
#include <cstring>

using namespace C150NETWORK;

string getStringFromStream();

int sqrt(int x[24], int y[24][15], int z[24][15]) {
    RPCPROXYSOCKET->write("sqrt", strlen("sqrt") + 1);

    for (int i0 = 0; i0 < 24; i++) { 
        string xi0StringRep = to_string(x[i0]);
        RPCPROXYSOCKET->write(xi0StringRep.c_str(), xi0StringRep.length() + 1);
    }

    for (int i0 = 0; i0 < 24; i++) { 
        for (int i1 = 0; i1 < 15; i++) { 
            string yi0i1StringRep = to_string(y[i0][i1]);
            RPCPROXYSOCKET->write(yi0i1StringRep.c_str(), yi0i1StringRep.length() + 1);
        }
    }

    for (int i0 = 0; i0 < 24; i++) { 
        for (int i1 = 0; i1 < 15; i++) { 
            string zi0i1StringRep = to_string(z[i0][i1]);
            RPCPROXYSOCKET->write(zi0i1StringRep.c_str(), zi0i1StringRep.length() + 1);
        }
    }

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
