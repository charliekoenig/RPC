#include "rpcstubhelper.h"
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

#include "stringstruct.idl"
#include "c150grading.h"

using namespace C150NETWORK;

string getStringFromStream();


void __findLastName () { 
    char doneBuffer[5] = "DONE";
    Person p;
    p.firstname = getStringFromStream();
    *GRADING << "Received value for p.firstname of type string - message: \"" << p.firstname << "\", length: " << p.firstname.length() + 1 << endl;

    p.lastname = getStringFromStream();
    *GRADING << "Received value for p.lastname of type string - message: \"" << p.lastname << "\", length: " << p.lastname.length() + 1 << endl;

    p.age = stoi(getStringFromStream());
    *GRADING << "Received value " << p.age << " (of type int in string form) for p.age" << endl;

    *GRADING << "Function findLastName invoked locally" << endl;
    string retVal = findLastName(p);
    RPCSTUBSOCKET->write(retVal.c_str(), retVal.length() + 1);
    *GRADING << "Sending value of retVal of type string - message: \"" << retVal << "\", length: " << retVal.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function findLastName invocation done"<< endl;
}

void dispatchFunction () { 
    string functionName = getStringFromStream();
    if (!RPCSTUBSOCKET-> eof()) {
        if (functionName == "findLastName") {
            __findLastName();
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
