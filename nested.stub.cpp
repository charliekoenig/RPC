#include "rpcstubhelper.h"
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

#include "nested.idl"
#include "c150grading.h"

using namespace C150NETWORK;

string getStringFromStream();


void __testArray () { 
    char doneBuffer[5] = "DONE";
    Inner arr[4];
    
    for (int i0 = 0; i0 < 4; i0++) { 
        arr[i0].x = stoi(getStringFromStream());
        *GRADING << "Received value " << arr[i0].x << " (of type int in string form) for arr[" << i0 << "].x" << endl;

        arr[i0].y = stof(getStringFromStream());
        *GRADING << "Received value " << arr[i0].y << " (of type float in string form) for arr[" << i0 << "].y" << endl;

        arr[i0].name = getStringFromStream();
        *GRADING << "Received value for arr[" << i0 << "].name of type string - message: \"" << arr[i0].name << "\", length: " << arr[i0].name.length() + 1 << endl;

    }


    *GRADING << "Function testArray invoked locally" << endl;
    float retVal = testArray(arr);
    string retValStringRep = to_string(retVal);
    *GRADING << "Converting " << retVal << " of type float to string" << endl;

    RPCSTUBSOCKET->write(retValStringRep.c_str(), retValStringRep.length() + 1);
    *GRADING << "Sending value of retVal in string form - message: \"" << retVal << "\", length: " << retValStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function testArray invocation done"<< endl;
}

void __testMixed () { 
    char doneBuffer[5] = "DONE";
    int simple[2];
    
    for (int i0 = 0; i0 < 2; i0++) { 
        simple[i0] = stoi(getStringFromStream());
        *GRADING << "Received value " << simple[i0] << " (of type int in string form) for simple[" << i0 << "]" << endl;

    }


    Inner structured[2];
    
    for (int i0 = 0; i0 < 2; i0++) { 
        structured[i0].x = stoi(getStringFromStream());
        *GRADING << "Received value " << structured[i0].x << " (of type int in string form) for structured[" << i0 << "].x" << endl;

        structured[i0].y = stof(getStringFromStream());
        *GRADING << "Received value " << structured[i0].y << " (of type float in string form) for structured[" << i0 << "].y" << endl;

        structured[i0].name = getStringFromStream();
        *GRADING << "Received value for structured[" << i0 << "].name of type string - message: \"" << structured[i0].name << "\", length: " << structured[i0].name.length() + 1 << endl;

    }


    *GRADING << "Function testMixed invoked locally" << endl;
    string retVal = testMixed(simple, structured);
    RPCSTUBSOCKET->write(retVal.c_str(), retVal.length() + 1);
    *GRADING << "Sending value of retVal of type string - message: \"" << retVal << "\", length: " << retVal.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function testMixed invocation done"<< endl;
}

void __testStruct () { 
    char doneBuffer[5] = "DONE";
    Outer obj;
    obj.data.x = stoi(getStringFromStream());
    *GRADING << "Received value " << obj.data.x << " (of type int in string form) for obj.data.x" << endl;

    obj.data.y = stof(getStringFromStream());
    *GRADING << "Received value " << obj.data.y << " (of type float in string form) for obj.data.y" << endl;

    obj.data.name = getStringFromStream();
    *GRADING << "Received value for obj.data.name of type string - message: \"" << obj.data.name << "\", length: " << obj.data.name.length() + 1 << endl;

    
    for (int i0 = 0; i0 < 3; i0++) { 
        obj.array[i0].x = stoi(getStringFromStream());
        *GRADING << "Received value " << obj.array[i0].x << " (of type int in string form) for obj.array[" << i0 << "].x" << endl;

        obj.array[i0].y = stof(getStringFromStream());
        *GRADING << "Received value " << obj.array[i0].y << " (of type float in string form) for obj.array[" << i0 << "].y" << endl;

        obj.array[i0].name = getStringFromStream();
        *GRADING << "Received value for obj.array[" << i0 << "].name of type string - message: \"" << obj.array[i0].name << "\", length: " << obj.array[i0].name.length() + 1 << endl;

    }


    
    for (int i0 = 0; i0 < 2; i0++) { 
        
        for (int i1 = 0; i1 < 2; i1++) { 
            obj.nums[i0][i1] = stoi(getStringFromStream());
            *GRADING << "Received value " << obj.nums[i0][i1] << " (of type int in string form) for obj.nums[" << i0 << "][" << i1 << "]" << endl;

        }

    }


    *GRADING << "Function testStruct invoked locally" << endl;
    int retVal = testStruct(obj);
    string retValStringRep = to_string(retVal);
    *GRADING << "Converting " << retVal << " of type int to string" << endl;

    RPCSTUBSOCKET->write(retValStringRep.c_str(), retValStringRep.length() + 1);
    *GRADING << "Sending value of retVal in string form - message: \"" << retVal << "\", length: " << retValStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function testStruct invocation done"<< endl;
}

void dispatchFunction () { 
    string functionName = getStringFromStream();
    if (!RPCSTUBSOCKET-> eof()) {
        if (functionName == "testStruct") {
            __testStruct();
        } else if (functionName == "testMixed") {
            __testMixed();
        } else if (functionName == "testArray") {
            __testArray();
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
