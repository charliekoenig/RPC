#include "rpcproxyhelper.h"
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

#include "nested.idl"
#include "c150grading.h"

using namespace C150NETWORK;

string getStringFromStream();


float testArray (Inner arr[4]) { 
    RPCPROXYSOCKET->write("testArray", strlen("testArray") + 1);
    *GRADING << "Invoking function testArray remotely - message: \"testArray\", length: " << strlen("testArray") + 1 << endl;
    *GRADING << "Serializing parameter arr"<< endl;
    
    for (int i0 = 0; i0 < 4; i0++) { 
        string arri0xStringRep = to_string(arr[i0].x);
        *GRADING << "Converting " << arr[i0].x << " of type int to string" << endl;

        RPCPROXYSOCKET->write(arri0xStringRep.c_str(), arri0xStringRep.length() + 1);
        *GRADING << "Sending value of arr[" << i0 << "].x in string form - message: \"" << arr[i0].x << "\", length: " << arri0xStringRep.length() + 1 << endl;

        string arri0yStringRep = to_string(arr[i0].y);
        *GRADING << "Converting " << arr[i0].y << " of type float to string" << endl;

        RPCPROXYSOCKET->write(arri0yStringRep.c_str(), arri0yStringRep.length() + 1);
        *GRADING << "Sending value of arr[" << i0 << "].y in string form - message: \"" << arr[i0].y << "\", length: " << arri0yStringRep.length() + 1 << endl;

        RPCPROXYSOCKET->write(arr[i0].name.c_str(), arr[i0].name.length() + 1);
        *GRADING << "Sending value of arr[" << i0 << "].name of type string - message: \"" << arr[i0].name << "\", length: " << arr[i0].name.length() + 1 << endl;

    }


    float retVal = stof(getStringFromStream());
    *GRADING << "Received value " << retVal << " (of type float in string form) for retVal" << endl;

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
    
    return retVal;
}

string testMixed (int simple[2], Inner structured[2]) { 
    RPCPROXYSOCKET->write("testMixed", strlen("testMixed") + 1);
    *GRADING << "Invoking function testMixed remotely - message: \"testMixed\", length: " << strlen("testMixed") + 1 << endl;
    *GRADING << "Serializing parameter simple"<< endl;
    
    for (int i0 = 0; i0 < 2; i0++) { 
        string simplei0StringRep = to_string(simple[i0]);
        *GRADING << "Converting " << simple[i0] << " of type int to string" << endl;

        RPCPROXYSOCKET->write(simplei0StringRep.c_str(), simplei0StringRep.length() + 1);
        *GRADING << "Sending value of simple[" << i0 << "] in string form - message: \"" << simple[i0] << "\", length: " << simplei0StringRep.length() + 1 << endl;

    }


    *GRADING << "Serializing parameter structured"<< endl;
    
    for (int i0 = 0; i0 < 2; i0++) { 
        string structuredi0xStringRep = to_string(structured[i0].x);
        *GRADING << "Converting " << structured[i0].x << " of type int to string" << endl;

        RPCPROXYSOCKET->write(structuredi0xStringRep.c_str(), structuredi0xStringRep.length() + 1);
        *GRADING << "Sending value of structured[" << i0 << "].x in string form - message: \"" << structured[i0].x << "\", length: " << structuredi0xStringRep.length() + 1 << endl;

        string structuredi0yStringRep = to_string(structured[i0].y);
        *GRADING << "Converting " << structured[i0].y << " of type float to string" << endl;

        RPCPROXYSOCKET->write(structuredi0yStringRep.c_str(), structuredi0yStringRep.length() + 1);
        *GRADING << "Sending value of structured[" << i0 << "].y in string form - message: \"" << structured[i0].y << "\", length: " << structuredi0yStringRep.length() + 1 << endl;

        RPCPROXYSOCKET->write(structured[i0].name.c_str(), structured[i0].name.length() + 1);
        *GRADING << "Sending value of structured[" << i0 << "].name of type string - message: \"" << structured[i0].name << "\", length: " << structured[i0].name.length() + 1 << endl;

    }


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

int testStruct (Outer obj) { 
    RPCPROXYSOCKET->write("testStruct", strlen("testStruct") + 1);
    *GRADING << "Invoking function testStruct remotely - message: \"testStruct\", length: " << strlen("testStruct") + 1 << endl;
    *GRADING << "Serializing parameter obj"<< endl;
    string objdataxStringRep = to_string(obj.data.x);
    *GRADING << "Converting " << obj.data.x << " of type int to string" << endl;

    RPCPROXYSOCKET->write(objdataxStringRep.c_str(), objdataxStringRep.length() + 1);
    *GRADING << "Sending value of obj.data.x in string form - message: \"" << obj.data.x << "\", length: " << objdataxStringRep.length() + 1 << endl;

    string objdatayStringRep = to_string(obj.data.y);
    *GRADING << "Converting " << obj.data.y << " of type float to string" << endl;

    RPCPROXYSOCKET->write(objdatayStringRep.c_str(), objdatayStringRep.length() + 1);
    *GRADING << "Sending value of obj.data.y in string form - message: \"" << obj.data.y << "\", length: " << objdatayStringRep.length() + 1 << endl;

    RPCPROXYSOCKET->write(obj.data.name.c_str(), obj.data.name.length() + 1);
    *GRADING << "Sending value of obj.data.name of type string - message: \"" << obj.data.name << "\", length: " << obj.data.name.length() + 1 << endl;

    
    for (int i0 = 0; i0 < 3; i0++) { 
        string objarrayi0xStringRep = to_string(obj.array[i0].x);
        *GRADING << "Converting " << obj.array[i0].x << " of type int to string" << endl;

        RPCPROXYSOCKET->write(objarrayi0xStringRep.c_str(), objarrayi0xStringRep.length() + 1);
        *GRADING << "Sending value of obj.array[" << i0 << "].x in string form - message: \"" << obj.array[i0].x << "\", length: " << objarrayi0xStringRep.length() + 1 << endl;

        string objarrayi0yStringRep = to_string(obj.array[i0].y);
        *GRADING << "Converting " << obj.array[i0].y << " of type float to string" << endl;

        RPCPROXYSOCKET->write(objarrayi0yStringRep.c_str(), objarrayi0yStringRep.length() + 1);
        *GRADING << "Sending value of obj.array[" << i0 << "].y in string form - message: \"" << obj.array[i0].y << "\", length: " << objarrayi0yStringRep.length() + 1 << endl;

        RPCPROXYSOCKET->write(obj.array[i0].name.c_str(), obj.array[i0].name.length() + 1);
        *GRADING << "Sending value of obj.array[" << i0 << "].name of type string - message: \"" << obj.array[i0].name << "\", length: " << obj.array[i0].name.length() + 1 << endl;

    }


    
    for (int i0 = 0; i0 < 2; i0++) { 
        
        for (int i1 = 0; i1 < 2; i1++) { 
            string objnumsi0i1StringRep = to_string(obj.nums[i0][i1]);
            *GRADING << "Converting " << obj.nums[i0][i1] << " of type int to string" << endl;

            RPCPROXYSOCKET->write(objnumsi0i1StringRep.c_str(), objnumsi0i1StringRep.length() + 1);
            *GRADING << "Sending value of obj.nums[" << i0 << "][" << i1 << "] in string form - message: \"" << obj.nums[i0][i1] << "\", length: " << objnumsi0i1StringRep.length() + 1 << endl;

        }

    }


    int retVal = stoi(getStringFromStream());
    *GRADING << "Received value " << retVal << " (of type int in string form) for retVal" << endl;

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
