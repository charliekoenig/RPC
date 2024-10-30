#include "arithmetic.idl"

#include "rpcstubhelper.h"

#include <cstdio>
#include <cstring>
#include <string>

using namespace C150NETWORK; 

void getFunctionNamefromStream();

void __add() {
        char doneBuffer[5] = "DONE";  // to write magic value DONE + null

        int param1;
        RPCSTUBSOCKET->read((char *) &param1, sizeof(param1));
        
        int param2;
        RPCSTUBSOCKET->read((char *) &param2, sizeof(param2));

        int retVal = add(param1, param2);

        RPCSTUBSOCKET->write((const char *) &retVal, sizeof(retVal));
        RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
}

void dispatchFunction() {
        int fNameLen;
        RPCSTUBSOCKET->read((char *) &fNameLen, sizeof(fNameLen));

        char functionNameBuffer[fNameLen + 1];

        RPCSTUBSOCKET->read(functionNameBuffer, fNameLen);
        functionNameBuffer[fNameLen] = '\0';

        if (!RPCSTUBSOCKET-> eof()) {
                if (strcmp(functionNameBuffer, "add") == 0) {
                        printf("function name received was: %s\n", functionNameBuffer);
                        __add();
                } else {
                        printf("function name received was wrong: %s\n", functionNameBuffer);
                        throw C150Exception("received above function name\n");
                }
        }
}
