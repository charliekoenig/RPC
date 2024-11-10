#include "structs.idl"

#include "rpcstubhelper.h"

#include <cstdio>
#include <cstring>
#include <vector>

using namespace C150NETWORK;

string getStringFromStream();

void __area() {
    char doneBuffer[5] = "DONE";

    rectangle r;

    r.x = stoi(getStringFromStream());
    r.y = stoi(getStringFromStream());
    int retVal = area(r);
    string retValStringRep = to_string(retVal);
    RPCSTUBSOCKET->write(retValStringRep.c_str(), retValStringRep.length() + 1);

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));    
}

void __findPerson() {
    char doneBuffer[5] = "DONE";

    ThreePeople tp;

    tp.p1.firstname = getStringFromStream();
    tp.p1.lastname = getStringFromStream();
    tp.p1.age = stoi(getStringFromStream());
    tp.p2.firstname = getStringFromStream();
    tp.p2.lastname = getStringFromStream();
    tp.p2.age = stoi(getStringFromStream());
    tp.p3.firstname = getStringFromStream();
    tp.p3.lastname = getStringFromStream();
    tp.p3.age = stoi(getStringFromStream());
    Person retVal = findPerson(tp);
    RPCSTUBSOCKET->write(retVal.firstname.c_str(), retVal.firstname.length() + 1);

    RPCSTUBSOCKET->write(retVal.lastname.c_str(), retVal.lastname.length() + 1);

    string retValageStringRep = to_string(retVal.age);
    RPCSTUBSOCKET->write(retValageStringRep.c_str(), retValageStringRep.length() + 1);

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));    
}

void dispatchFunction() {
    string functionName = getStringFromStream();

    if (!RPCSTUBSOCKET-> eof()) {
        if (functionName == "findPerson") {
            __findPerson();
        } else if (functionName == "area") {
            __area();
        } else {
            throw C150Exception("received above function name\n");
        }
    }
}

string getStringFromStream() {
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
