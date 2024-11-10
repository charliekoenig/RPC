#include "structwitharray.idl"

#include "rpcstubhelper.h"

#include <cstdio>
#include <cstring>
#include <vector>

using namespace C150NETWORK;

string getStringFromStream();

void dispatchFunction() {
    string functionName = getStringFromStream();


}

