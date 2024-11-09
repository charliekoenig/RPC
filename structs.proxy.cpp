#include "structs.idl"

#include "rpcproxyhelper.h"

#include <cstdio>
#include <cstring>

using namespace C150NETWORK;

string getStringFromStream();

int area(rectangle r) {
    RPCPROXYSOCKET->write("area", strlen("area") + 1);

    string rxStringRep = to_string(r.x);
    RPCPROXYSOCKET->write(rxStringRep.c_str(), rxStringRep.length() + 1);

    string ryStringRep = to_string(r.y);
    RPCPROXYSOCKET->write(ryStringRep.c_str(), ryStringRep.length() + 1);

    int retVal = stoi(getStringFromStream());
    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    return retVal;
}

Person findPerson(ThreePeople tp) {
    RPCPROXYSOCKET->write("findPerson", strlen("findPerson") + 1);

    RPCPROXYSOCKET->write(tp.p1.firstname.c_str(), tp.p1.firstname.length() + 1);

    RPCPROXYSOCKET->write(tp.p1.lastname.c_str(), tp.p1.lastname.length() + 1);

    string tpp1ageStringRep = to_string(tp.p1.age);
    RPCPROXYSOCKET->write(tpp1ageStringRep.c_str(), tpp1ageStringRep.length() + 1);

    RPCPROXYSOCKET->write(tp.p2.firstname.c_str(), tp.p2.firstname.length() + 1);

    RPCPROXYSOCKET->write(tp.p2.lastname.c_str(), tp.p2.lastname.length() + 1);

    string tpp2ageStringRep = to_string(tp.p2.age);
    RPCPROXYSOCKET->write(tpp2ageStringRep.c_str(), tpp2ageStringRep.length() + 1);

    RPCPROXYSOCKET->write(tp.p3.firstname.c_str(), tp.p3.firstname.length() + 1);

    RPCPROXYSOCKET->write(tp.p3.lastname.c_str(), tp.p3.lastname.length() + 1);

    string tpp3ageStringRep = to_string(tp.p3.age);
    RPCPROXYSOCKET->write(tpp3ageStringRep.c_str(), tpp3ageStringRep.length() + 1);

    Person retVal;

    retVal.firstname = getStringFromStream();
    retVal.lastname = getStringFromStream();
    retVal.age = stoi(getStringFromStream());
    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    return retVal;
}

