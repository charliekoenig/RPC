#include "structs.idl"

#include "rpcproxyhelper.h"

#include <cstdio>
#include <cstring>

using namespace C150NETWORK;

int area(rectangle r) {
    int fNameLen = strlen("area");
    RPCPROXYSOCKET->write((const char *) &fNameLen, sizeof(fNameLen));
    RPCPROXYSOCKET->write("area", strlen("area"));

string numStringRep = to_string(r.x);
RPCPROXYSOCKET->write(numStringRep.c_str(), numStringRep.length() + 1);

string numStringRep = to_string(r.y);
RPCPROXYSOCKET->write(numStringRep.c_str(), numStringRep.length() + 1);

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
}

Person findPerson(ThreePeople tp) {
    int fNameLen = strlen("findPerson");
    RPCPROXYSOCKET->write((const char *) &fNameLen, sizeof(fNameLen));
    RPCPROXYSOCKET->write("findPerson", strlen("findPerson"));

RPCPROXYSOCKET->write(tp.p1.firstname.c_str(), tp.p1.firstname.length() + 1);

RPCPROXYSOCKET->write(tp.p1.lastname.c_str(), tp.p1.lastname.length() + 1);

string numStringRep = to_string(tp.p1.age);
RPCPROXYSOCKET->write(numStringRep.c_str(), numStringRep.length() + 1);

RPCPROXYSOCKET->write(tp.p2.firstname.c_str(), tp.p2.firstname.length() + 1);

RPCPROXYSOCKET->write(tp.p2.lastname.c_str(), tp.p2.lastname.length() + 1);

string numStringRep = to_string(tp.p2.age);
RPCPROXYSOCKET->write(numStringRep.c_str(), numStringRep.length() + 1);

RPCPROXYSOCKET->write(tp.p3.firstname.c_str(), tp.p3.firstname.length() + 1);

RPCPROXYSOCKET->write(tp.p3.lastname.c_str(), tp.p3.lastname.length() + 1);

string numStringRep = to_string(tp.p3.age);
RPCPROXYSOCKET->write(numStringRep.c_str(), numStringRep.length() + 1);

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
}

