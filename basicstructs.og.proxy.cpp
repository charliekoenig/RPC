#include "basicstructs.idl"

#include "rpcproxyhelper.h"

#include <cstdio>
#include <cstring>

using namespace C150NETWORK;

string getStringFromStream();

int oldestAge(StructWithArrays x[10]) {
    RPCPROXYSOCKET->write("oldestAge", strlen("oldestAge") + 1);

    for (int i0 = 0; i0 < 10; i0++) { 
        for (int i1 = 0; i1 < 10; i1++) { 
            string xi0peoplei1ageStringRep = to_string(x[i0].people[i1].age);
            RPCPROXYSOCKET->write(xi0peoplei1ageStringRep.c_str(), xi0peoplei1ageStringRep.length() + 1);
            cout << "From proxy sent: [" << i0 << "][" << i1 <<"] = " << xi0peoplei1ageStringRep << " for age " << x[i0].people[i1].age << endl;
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
