#include "rpcproxyhelper.h"
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

#include "stringstruct.idl"
#include "c150grading.h"

using namespace C150NETWORK;

string getStringFromStream();


string findLastName (Person p) { 
    RPCPROXYSOCKET->write("findLastName", strlen("findLastName") + 1);
    *GRADING << "Invoking function findLastName remotely - message: \"findLastName\", length: " << strlen("findLastName") + 1 << endl;
    *GRADING << "Serializing parameter p"<< endl;
    RPCPROXYSOCKET->write(p.firstname.c_str(), p.firstname.length() + 1);
    *GRADING << "Sending value of p.firstname of type string - message: \"" << p.firstname << "\", length: " << p.firstname.length() + 1 << endl;

    RPCPROXYSOCKET->write(p.lastname.c_str(), p.lastname.length() + 1);
    *GRADING << "Sending value of p.lastname of type string - message: \"" << p.lastname << "\", length: " << p.lastname.length() + 1 << endl;

    string pageStringRep = to_string(p.age);
    *GRADING << "Converting " << p.age << " of type int to string" << endl;

    RPCPROXYSOCKET->write(pageStringRep.c_str(), pageStringRep.length() + 1);
    *GRADING << "Sending value of p.age in string form - message: \"" << p.age << "\", length: " << pageStringRep.length() + 1 << endl;

    string retVal = getStringFromStream();
    *GRADING << "Received value for retVal of type string - message: \"" << retVal << "\", length: " << retVal.length() + 1 << endl;

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
