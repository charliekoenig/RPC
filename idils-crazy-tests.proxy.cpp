#include "rpcproxyhelper.h"
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

#include "idils-crazy-tests.idl"
#include "c150grading.h"

using namespace C150NETWORK;

string getStringFromStream();


float fReturnAgeOfPerson (Person idil) { 
    RPCPROXYSOCKET->write("fReturnAgeOfPerson", strlen("fReturnAgeOfPerson") + 1);
    *GRADING << "Invoking function fReturnAgeOfPerson remotely - message: \"fReturnAgeOfPerson\", length: " << strlen("fReturnAgeOfPerson") + 1 << endl;
    *GRADING << "Serializing parameter idil"<< endl;
    RPCPROXYSOCKET->write(idil.name.c_str(), idil.name.length() + 1);
    *GRADING << "Sending value of idil.name of type string - message: \"" << idil.name << "\", length: " << idil.name.length() + 1 << endl;

    string idilageStringRep = to_string(idil.age);
    *GRADING << "Converting " << idil.age << " of type int to string" << endl;

    RPCPROXYSOCKET->write(idilageStringRep.c_str(), idilageStringRep.length() + 1);
    *GRADING << "Sending value of idil.age in string form - message: \"" << idil.age << "\", length: " << idilageStringRep.length() + 1 << endl;

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

float fReturnAgeOfRelativeOfPerson (Relative idils_sister) { 
    RPCPROXYSOCKET->write("fReturnAgeOfRelativeOfPerson", strlen("fReturnAgeOfRelativeOfPerson") + 1);
    *GRADING << "Invoking function fReturnAgeOfRelativeOfPerson remotely - message: \"fReturnAgeOfRelativeOfPerson\", length: " << strlen("fReturnAgeOfRelativeOfPerson") + 1 << endl;
    *GRADING << "Serializing parameter idils_sister"<< endl;
    RPCPROXYSOCKET->write(idils_sister.name.c_str(), idils_sister.name.length() + 1);
    *GRADING << "Sending value of idils_sister.name of type string - message: \"" << idils_sister.name << "\", length: " << idils_sister.name.length() + 1 << endl;

    string idils_sisterageStringRep = to_string(idils_sister.age);
    *GRADING << "Converting " << idils_sister.age << " of type int to string" << endl;

    RPCPROXYSOCKET->write(idils_sisterageStringRep.c_str(), idils_sisterageStringRep.length() + 1);
    *GRADING << "Sending value of idils_sister.age in string form - message: \"" << idils_sister.age << "\", length: " << idils_sisterageStringRep.length() + 1 << endl;

    RPCPROXYSOCKET->write(idils_sister.r.name.c_str(), idils_sister.r.name.length() + 1);
    *GRADING << "Sending value of idils_sister.r.name of type string - message: \"" << idils_sister.r.name << "\", length: " << idils_sister.r.name.length() + 1 << endl;

    string idils_sisterrageStringRep = to_string(idils_sister.r.age);
    *GRADING << "Converting " << idils_sister.r.age << " of type int to string" << endl;

    RPCPROXYSOCKET->write(idils_sisterrageStringRep.c_str(), idils_sisterrageStringRep.length() + 1);
    *GRADING << "Sending value of idils_sister.r.age in string form - message: \"" << idils_sister.r.age << "\", length: " << idils_sisterrageStringRep.length() + 1 << endl;

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

float fReturnAverageAgeOfFamilies (FamilyOfThree fot[5]) { 
    RPCPROXYSOCKET->write("fReturnAverageAgeOfFamilies", strlen("fReturnAverageAgeOfFamilies") + 1);
    *GRADING << "Invoking function fReturnAverageAgeOfFamilies remotely - message: \"fReturnAverageAgeOfFamilies\", length: " << strlen("fReturnAverageAgeOfFamilies") + 1 << endl;
    *GRADING << "Serializing parameter fot"<< endl;
    
    for (int i0 = 0; i0 < 5; i0++) { 
        RPCPROXYSOCKET->write(fot[i0].lastname.c_str(), fot[i0].lastname.length() + 1);
        *GRADING << "Sending value of fot[" << i0 << "].lastname of type string - message: \"" << fot[i0].lastname << "\", length: " << fot[i0].lastname.length() + 1 << endl;

        
        for (int i1 = 0; i1 < 3; i1++) { 
            RPCPROXYSOCKET->write(fot[i0].family_members[i1].name.c_str(), fot[i0].family_members[i1].name.length() + 1);
            *GRADING << "Sending value of fot[" << i0 << "].family_members[" << i1 << "].name of type string - message: \"" << fot[i0].family_members[i1].name << "\", length: " << fot[i0].family_members[i1].name.length() + 1 << endl;

            string foti0family_membersi1ageStringRep = to_string(fot[i0].family_members[i1].age);
            *GRADING << "Converting " << fot[i0].family_members[i1].age << " of type int to string" << endl;

            RPCPROXYSOCKET->write(foti0family_membersi1ageStringRep.c_str(), foti0family_membersi1ageStringRep.length() + 1);
            *GRADING << "Sending value of fot[" << i0 << "].family_members[" << i1 << "].age in string form - message: \"" << fot[i0].family_members[i1].age << "\", length: " << foti0family_membersi1ageStringRep.length() + 1 << endl;

        }


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

float fReturnAverageAgeOfFamily (FamilyOfThree fot) { 
    RPCPROXYSOCKET->write("fReturnAverageAgeOfFamily", strlen("fReturnAverageAgeOfFamily") + 1);
    *GRADING << "Invoking function fReturnAverageAgeOfFamily remotely - message: \"fReturnAverageAgeOfFamily\", length: " << strlen("fReturnAverageAgeOfFamily") + 1 << endl;
    *GRADING << "Serializing parameter fot"<< endl;
    RPCPROXYSOCKET->write(fot.lastname.c_str(), fot.lastname.length() + 1);
    *GRADING << "Sending value of fot.lastname of type string - message: \"" << fot.lastname << "\", length: " << fot.lastname.length() + 1 << endl;

    
    for (int i0 = 0; i0 < 3; i0++) { 
        RPCPROXYSOCKET->write(fot.family_members[i0].name.c_str(), fot.family_members[i0].name.length() + 1);
        *GRADING << "Sending value of fot.family_members[" << i0 << "].name of type string - message: \"" << fot.family_members[i0].name << "\", length: " << fot.family_members[i0].name.length() + 1 << endl;

        string fotfamily_membersi0ageStringRep = to_string(fot.family_members[i0].age);
        *GRADING << "Converting " << fot.family_members[i0].age << " of type int to string" << endl;

        RPCPROXYSOCKET->write(fotfamily_membersi0ageStringRep.c_str(), fotfamily_membersi0ageStringRep.length() + 1);
        *GRADING << "Sending value of fot.family_members[" << i0 << "].age in string form - message: \"" << fot.family_members[i0].age << "\", length: " << fotfamily_membersi0ageStringRep.length() + 1 << endl;

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

float fReturnAverageAgeOfPeople (Person people[5][4]) { 
    RPCPROXYSOCKET->write("fReturnAverageAgeOfPeople", strlen("fReturnAverageAgeOfPeople") + 1);
    *GRADING << "Invoking function fReturnAverageAgeOfPeople remotely - message: \"fReturnAverageAgeOfPeople\", length: " << strlen("fReturnAverageAgeOfPeople") + 1 << endl;
    *GRADING << "Serializing parameter people"<< endl;
    
    for (int i0 = 0; i0 < 5; i0++) { 
        
        for (int i1 = 0; i1 < 4; i1++) { 
            RPCPROXYSOCKET->write(people[i0][i1].name.c_str(), people[i0][i1].name.length() + 1);
            *GRADING << "Sending value of people[" << i0 << "][" << i1 << "].name of type string - message: \"" << people[i0][i1].name << "\", length: " << people[i0][i1].name.length() + 1 << endl;

            string peoplei0i1ageStringRep = to_string(people[i0][i1].age);
            *GRADING << "Converting " << people[i0][i1].age << " of type int to string" << endl;

            RPCPROXYSOCKET->write(peoplei0i1ageStringRep.c_str(), peoplei0i1ageStringRep.length() + 1);
            *GRADING << "Sending value of people[" << i0 << "][" << i1 << "].age in string form - message: \"" << people[i0][i1].age << "\", length: " << peoplei0i1ageStringRep.length() + 1 << endl;

        }

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

float fReturnAverageAgeOfPersons (Person persons[5]) { 
    RPCPROXYSOCKET->write("fReturnAverageAgeOfPersons", strlen("fReturnAverageAgeOfPersons") + 1);
    *GRADING << "Invoking function fReturnAverageAgeOfPersons remotely - message: \"fReturnAverageAgeOfPersons\", length: " << strlen("fReturnAverageAgeOfPersons") + 1 << endl;
    *GRADING << "Serializing parameter persons"<< endl;
    
    for (int i0 = 0; i0 < 5; i0++) { 
        RPCPROXYSOCKET->write(persons[i0].name.c_str(), persons[i0].name.length() + 1);
        *GRADING << "Sending value of persons[" << i0 << "].name of type string - message: \"" << persons[i0].name << "\", length: " << persons[i0].name.length() + 1 << endl;

        string personsi0ageStringRep = to_string(persons[i0].age);
        *GRADING << "Converting " << persons[i0].age << " of type int to string" << endl;

        RPCPROXYSOCKET->write(personsi0ageStringRep.c_str(), personsi0ageStringRep.length() + 1);
        *GRADING << "Sending value of persons[" << i0 << "].age in string form - message: \"" << persons[i0].age << "\", length: " << personsi0ageStringRep.length() + 1 << endl;

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

float fReturnInputFloat (float input) { 
    RPCPROXYSOCKET->write("fReturnInputFloat", strlen("fReturnInputFloat") + 1);
    *GRADING << "Invoking function fReturnInputFloat remotely - message: \"fReturnInputFloat\", length: " << strlen("fReturnInputFloat") + 1 << endl;
    *GRADING << "Serializing parameter input"<< endl;
    string inputStringRep = to_string(input);
    *GRADING << "Converting " << input << " of type float to string" << endl;

    RPCPROXYSOCKET->write(inputStringRep.c_str(), inputStringRep.length() + 1);
    *GRADING << "Sending value of input in string form - message: \"" << input << "\", length: " << inputStringRep.length() + 1 << endl;

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

float fReturnInputInt (int input) { 
    RPCPROXYSOCKET->write("fReturnInputInt", strlen("fReturnInputInt") + 1);
    *GRADING << "Invoking function fReturnInputInt remotely - message: \"fReturnInputInt\", length: " << strlen("fReturnInputInt") + 1 << endl;
    *GRADING << "Serializing parameter input"<< endl;
    string inputStringRep = to_string(input);
    *GRADING << "Converting " << input << " of type int to string" << endl;

    RPCPROXYSOCKET->write(inputStringRep.c_str(), inputStringRep.length() + 1);
    *GRADING << "Sending value of input in string form - message: \"" << input << "\", length: " << inputStringRep.length() + 1 << endl;

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

float fReturnInputString (string input) { 
    RPCPROXYSOCKET->write("fReturnInputString", strlen("fReturnInputString") + 1);
    *GRADING << "Invoking function fReturnInputString remotely - message: \"fReturnInputString\", length: " << strlen("fReturnInputString") + 1 << endl;
    *GRADING << "Serializing parameter input"<< endl;
    RPCPROXYSOCKET->write(input.c_str(), input.length() + 1);
    *GRADING << "Sending value of input of type string - message: \"" << input << "\", length: " << input.length() + 1 << endl;

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

float fReturnTwo () { 
    RPCPROXYSOCKET->write("fReturnTwo", strlen("fReturnTwo") + 1);
    *GRADING << "Invoking function fReturnTwo remotely - message: \"fReturnTwo\", length: " << strlen("fReturnTwo") + 1 << endl;
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

Person makeCopyOfPerson (Person p) { 
    RPCPROXYSOCKET->write("makeCopyOfPerson", strlen("makeCopyOfPerson") + 1);
    *GRADING << "Invoking function makeCopyOfPerson remotely - message: \"makeCopyOfPerson\", length: " << strlen("makeCopyOfPerson") + 1 << endl;
    *GRADING << "Serializing parameter p"<< endl;
    RPCPROXYSOCKET->write(p.name.c_str(), p.name.length() + 1);
    *GRADING << "Sending value of p.name of type string - message: \"" << p.name << "\", length: " << p.name.length() + 1 << endl;

    string pageStringRep = to_string(p.age);
    *GRADING << "Converting " << p.age << " of type int to string" << endl;

    RPCPROXYSOCKET->write(pageStringRep.c_str(), pageStringRep.length() + 1);
    *GRADING << "Sending value of p.age in string form - message: \"" << p.age << "\", length: " << pageStringRep.length() + 1 << endl;

    Person retVal;
    retVal.name = getStringFromStream();
    *GRADING << "Received value for retVal.name of type string - message: \"" << retVal.name << "\", length: " << retVal.name.length() + 1 << endl;

    retVal.age = stoi(getStringFromStream());
    *GRADING << "Received value " << retVal.age << " (of type int in string form) for retVal.age" << endl;

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
    
    return retVal;
}

FamilyOfThree makeFamilyOfThree () { 
    RPCPROXYSOCKET->write("makeFamilyOfThree", strlen("makeFamilyOfThree") + 1);
    *GRADING << "Invoking function makeFamilyOfThree remotely - message: \"makeFamilyOfThree\", length: " << strlen("makeFamilyOfThree") + 1 << endl;
    FamilyOfThree retVal;
    retVal.lastname = getStringFromStream();
    *GRADING << "Received value for retVal.lastname of type string - message: \"" << retVal.lastname << "\", length: " << retVal.lastname.length() + 1 << endl;

    
    for (int i0 = 0; i0 < 3; i0++) { 
        retVal.family_members[i0].name = getStringFromStream();
        *GRADING << "Received value for retVal.family_members[" << i0 << "].name of type string - message: \"" << retVal.family_members[i0].name << "\", length: " << retVal.family_members[i0].name.length() + 1 << endl;

        retVal.family_members[i0].age = stoi(getStringFromStream());
        *GRADING << "Received value " << retVal.family_members[i0].age << " (of type int in string form) for retVal.family_members[" << i0 << "].age" << endl;

    }


    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
    
    return retVal;
}

FamilyOfThree makeFamilyWithAges (int age1, int age2, int age3) { 
    RPCPROXYSOCKET->write("makeFamilyWithAges", strlen("makeFamilyWithAges") + 1);
    *GRADING << "Invoking function makeFamilyWithAges remotely - message: \"makeFamilyWithAges\", length: " << strlen("makeFamilyWithAges") + 1 << endl;
    *GRADING << "Serializing parameter age1"<< endl;
    string age1StringRep = to_string(age1);
    *GRADING << "Converting " << age1 << " of type int to string" << endl;

    RPCPROXYSOCKET->write(age1StringRep.c_str(), age1StringRep.length() + 1);
    *GRADING << "Sending value of age1 in string form - message: \"" << age1 << "\", length: " << age1StringRep.length() + 1 << endl;

    *GRADING << "Serializing parameter age2"<< endl;
    string age2StringRep = to_string(age2);
    *GRADING << "Converting " << age2 << " of type int to string" << endl;

    RPCPROXYSOCKET->write(age2StringRep.c_str(), age2StringRep.length() + 1);
    *GRADING << "Sending value of age2 in string form - message: \"" << age2 << "\", length: " << age2StringRep.length() + 1 << endl;

    *GRADING << "Serializing parameter age3"<< endl;
    string age3StringRep = to_string(age3);
    *GRADING << "Converting " << age3 << " of type int to string" << endl;

    RPCPROXYSOCKET->write(age3StringRep.c_str(), age3StringRep.length() + 1);
    *GRADING << "Sending value of age3 in string form - message: \"" << age3 << "\", length: " << age3StringRep.length() + 1 << endl;

    FamilyOfThree retVal;
    retVal.lastname = getStringFromStream();
    *GRADING << "Received value for retVal.lastname of type string - message: \"" << retVal.lastname << "\", length: " << retVal.lastname.length() + 1 << endl;

    
    for (int i0 = 0; i0 < 3; i0++) { 
        retVal.family_members[i0].name = getStringFromStream();
        *GRADING << "Received value for retVal.family_members[" << i0 << "].name of type string - message: \"" << retVal.family_members[i0].name << "\", length: " << retVal.family_members[i0].name.length() + 1 << endl;

        retVal.family_members[i0].age = stoi(getStringFromStream());
        *GRADING << "Received value " << retVal.family_members[i0].age << " (of type int in string form) for retVal.family_members[" << i0 << "].age" << endl;

    }


    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
    
    return retVal;
}

FamilyOfThree makeFamilyWithName (string lastname) { 
    RPCPROXYSOCKET->write("makeFamilyWithName", strlen("makeFamilyWithName") + 1);
    *GRADING << "Invoking function makeFamilyWithName remotely - message: \"makeFamilyWithName\", length: " << strlen("makeFamilyWithName") + 1 << endl;
    *GRADING << "Serializing parameter lastname"<< endl;
    RPCPROXYSOCKET->write(lastname.c_str(), lastname.length() + 1);
    *GRADING << "Sending value of lastname of type string - message: \"" << lastname << "\", length: " << lastname.length() + 1 << endl;

    FamilyOfThree retVal;
    retVal.lastname = getStringFromStream();
    *GRADING << "Received value for retVal.lastname of type string - message: \"" << retVal.lastname << "\", length: " << retVal.lastname.length() + 1 << endl;

    
    for (int i0 = 0; i0 < 3; i0++) { 
        retVal.family_members[i0].name = getStringFromStream();
        *GRADING << "Received value for retVal.family_members[" << i0 << "].name of type string - message: \"" << retVal.family_members[i0].name << "\", length: " << retVal.family_members[i0].name.length() + 1 << endl;

        retVal.family_members[i0].age = stoi(getStringFromStream());
        *GRADING << "Received value " << retVal.family_members[i0].age << " (of type int in string form) for retVal.family_members[" << i0 << "].age" << endl;

    }


    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
    
    return retVal;
}

FamilyOfThree makeFamilyWithPersonArray (Person fofthree[3]) { 
    RPCPROXYSOCKET->write("makeFamilyWithPersonArray", strlen("makeFamilyWithPersonArray") + 1);
    *GRADING << "Invoking function makeFamilyWithPersonArray remotely - message: \"makeFamilyWithPersonArray\", length: " << strlen("makeFamilyWithPersonArray") + 1 << endl;
    *GRADING << "Serializing parameter fofthree"<< endl;
    
    for (int i0 = 0; i0 < 3; i0++) { 
        RPCPROXYSOCKET->write(fofthree[i0].name.c_str(), fofthree[i0].name.length() + 1);
        *GRADING << "Sending value of fofthree[" << i0 << "].name of type string - message: \"" << fofthree[i0].name << "\", length: " << fofthree[i0].name.length() + 1 << endl;

        string fofthreei0ageStringRep = to_string(fofthree[i0].age);
        *GRADING << "Converting " << fofthree[i0].age << " of type int to string" << endl;

        RPCPROXYSOCKET->write(fofthreei0ageStringRep.c_str(), fofthreei0ageStringRep.length() + 1);
        *GRADING << "Sending value of fofthree[" << i0 << "].age in string form - message: \"" << fofthree[i0].age << "\", length: " << fofthreei0ageStringRep.length() + 1 << endl;

    }


    FamilyOfThree retVal;
    retVal.lastname = getStringFromStream();
    *GRADING << "Received value for retVal.lastname of type string - message: \"" << retVal.lastname << "\", length: " << retVal.lastname.length() + 1 << endl;

    
    for (int i0 = 0; i0 < 3; i0++) { 
        retVal.family_members[i0].name = getStringFromStream();
        *GRADING << "Received value for retVal.family_members[" << i0 << "].name of type string - message: \"" << retVal.family_members[i0].name << "\", length: " << retVal.family_members[i0].name.length() + 1 << endl;

        retVal.family_members[i0].age = stoi(getStringFromStream());
        *GRADING << "Received value " << retVal.family_members[i0].age << " (of type int in string form) for retVal.family_members[" << i0 << "].age" << endl;

    }


    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
    
    return retVal;
}

FamilyOfThree makeFamilyWithPersons (Person p1, Person p2, Person p3) { 
    RPCPROXYSOCKET->write("makeFamilyWithPersons", strlen("makeFamilyWithPersons") + 1);
    *GRADING << "Invoking function makeFamilyWithPersons remotely - message: \"makeFamilyWithPersons\", length: " << strlen("makeFamilyWithPersons") + 1 << endl;
    *GRADING << "Serializing parameter p1"<< endl;
    RPCPROXYSOCKET->write(p1.name.c_str(), p1.name.length() + 1);
    *GRADING << "Sending value of p1.name of type string - message: \"" << p1.name << "\", length: " << p1.name.length() + 1 << endl;

    string p1ageStringRep = to_string(p1.age);
    *GRADING << "Converting " << p1.age << " of type int to string" << endl;

    RPCPROXYSOCKET->write(p1ageStringRep.c_str(), p1ageStringRep.length() + 1);
    *GRADING << "Sending value of p1.age in string form - message: \"" << p1.age << "\", length: " << p1ageStringRep.length() + 1 << endl;

    *GRADING << "Serializing parameter p2"<< endl;
    RPCPROXYSOCKET->write(p2.name.c_str(), p2.name.length() + 1);
    *GRADING << "Sending value of p2.name of type string - message: \"" << p2.name << "\", length: " << p2.name.length() + 1 << endl;

    string p2ageStringRep = to_string(p2.age);
    *GRADING << "Converting " << p2.age << " of type int to string" << endl;

    RPCPROXYSOCKET->write(p2ageStringRep.c_str(), p2ageStringRep.length() + 1);
    *GRADING << "Sending value of p2.age in string form - message: \"" << p2.age << "\", length: " << p2ageStringRep.length() + 1 << endl;

    *GRADING << "Serializing parameter p3"<< endl;
    RPCPROXYSOCKET->write(p3.name.c_str(), p3.name.length() + 1);
    *GRADING << "Sending value of p3.name of type string - message: \"" << p3.name << "\", length: " << p3.name.length() + 1 << endl;

    string p3ageStringRep = to_string(p3.age);
    *GRADING << "Converting " << p3.age << " of type int to string" << endl;

    RPCPROXYSOCKET->write(p3ageStringRep.c_str(), p3ageStringRep.length() + 1);
    *GRADING << "Sending value of p3.age in string form - message: \"" << p3.age << "\", length: " << p3ageStringRep.length() + 1 << endl;

    FamilyOfThree retVal;
    retVal.lastname = getStringFromStream();
    *GRADING << "Received value for retVal.lastname of type string - message: \"" << retVal.lastname << "\", length: " << retVal.lastname.length() + 1 << endl;

    
    for (int i0 = 0; i0 < 3; i0++) { 
        retVal.family_members[i0].name = getStringFromStream();
        *GRADING << "Received value for retVal.family_members[" << i0 << "].name of type string - message: \"" << retVal.family_members[i0].name << "\", length: " << retVal.family_members[i0].name.length() + 1 << endl;

        retVal.family_members[i0].age = stoi(getStringFromStream());
        *GRADING << "Received value " << retVal.family_members[i0].age << " (of type int in string form) for retVal.family_members[" << i0 << "].age" << endl;

    }


    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
    
    return retVal;
}

Person makePersonAgeAndAHalfYearsOld (float age) { 
    RPCPROXYSOCKET->write("makePersonAgeAndAHalfYearsOld", strlen("makePersonAgeAndAHalfYearsOld") + 1);
    *GRADING << "Invoking function makePersonAgeAndAHalfYearsOld remotely - message: \"makePersonAgeAndAHalfYearsOld\", length: " << strlen("makePersonAgeAndAHalfYearsOld") + 1 << endl;
    *GRADING << "Serializing parameter age"<< endl;
    string ageStringRep = to_string(age);
    *GRADING << "Converting " << age << " of type float to string" << endl;

    RPCPROXYSOCKET->write(ageStringRep.c_str(), ageStringRep.length() + 1);
    *GRADING << "Sending value of age in string form - message: \"" << age << "\", length: " << ageStringRep.length() + 1 << endl;

    Person retVal;
    retVal.name = getStringFromStream();
    *GRADING << "Received value for retVal.name of type string - message: \"" << retVal.name << "\", length: " << retVal.name.length() + 1 << endl;

    retVal.age = stoi(getStringFromStream());
    *GRADING << "Received value " << retVal.age << " (of type int in string form) for retVal.age" << endl;

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
    
    return retVal;
}

Person makePersonAgeYearsOld (int age) { 
    RPCPROXYSOCKET->write("makePersonAgeYearsOld", strlen("makePersonAgeYearsOld") + 1);
    *GRADING << "Invoking function makePersonAgeYearsOld remotely - message: \"makePersonAgeYearsOld\", length: " << strlen("makePersonAgeYearsOld") + 1 << endl;
    *GRADING << "Serializing parameter age"<< endl;
    string ageStringRep = to_string(age);
    *GRADING << "Converting " << age << " of type int to string" << endl;

    RPCPROXYSOCKET->write(ageStringRep.c_str(), ageStringRep.length() + 1);
    *GRADING << "Sending value of age in string form - message: \"" << age << "\", length: " << ageStringRep.length() + 1 << endl;

    Person retVal;
    retVal.name = getStringFromStream();
    *GRADING << "Received value for retVal.name of type string - message: \"" << retVal.name << "\", length: " << retVal.name.length() + 1 << endl;

    retVal.age = stoi(getStringFromStream());
    *GRADING << "Received value " << retVal.age << " (of type int in string form) for retVal.age" << endl;

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
    
    return retVal;
}

Person makePersonWithName (string name) { 
    RPCPROXYSOCKET->write("makePersonWithName", strlen("makePersonWithName") + 1);
    *GRADING << "Invoking function makePersonWithName remotely - message: \"makePersonWithName\", length: " << strlen("makePersonWithName") + 1 << endl;
    *GRADING << "Serializing parameter name"<< endl;
    RPCPROXYSOCKET->write(name.c_str(), name.length() + 1);
    *GRADING << "Sending value of name of type string - message: \"" << name << "\", length: " << name.length() + 1 << endl;

    Person retVal;
    retVal.name = getStringFromStream();
    *GRADING << "Received value for retVal.name of type string - message: \"" << retVal.name << "\", length: " << retVal.name.length() + 1 << endl;

    retVal.age = stoi(getStringFromStream());
    *GRADING << "Received value " << retVal.age << " (of type int in string form) for retVal.age" << endl;

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
    
    return retVal;
}

Person makeRandomPerson () { 
    RPCPROXYSOCKET->write("makeRandomPerson", strlen("makeRandomPerson") + 1);
    *GRADING << "Invoking function makeRandomPerson remotely - message: \"makeRandomPerson\", length: " << strlen("makeRandomPerson") + 1 << endl;
    Person retVal;
    retVal.name = getStringFromStream();
    *GRADING << "Received value for retVal.name of type string - message: \"" << retVal.name << "\", length: " << retVal.name.length() + 1 << endl;

    retVal.age = stoi(getStringFromStream());
    *GRADING << "Received value " << retVal.age << " (of type int in string form) for retVal.age" << endl;

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
    
    return retVal;
}

void printFamilies (FamilyOfThree fot[5]) { 
    RPCPROXYSOCKET->write("printFamilies", strlen("printFamilies") + 1);
    *GRADING << "Invoking function printFamilies remotely - message: \"printFamilies\", length: " << strlen("printFamilies") + 1 << endl;
    *GRADING << "Serializing parameter fot"<< endl;
    
    for (int i0 = 0; i0 < 5; i0++) { 
        RPCPROXYSOCKET->write(fot[i0].lastname.c_str(), fot[i0].lastname.length() + 1);
        *GRADING << "Sending value of fot[" << i0 << "].lastname of type string - message: \"" << fot[i0].lastname << "\", length: " << fot[i0].lastname.length() + 1 << endl;

        
        for (int i1 = 0; i1 < 3; i1++) { 
            RPCPROXYSOCKET->write(fot[i0].family_members[i1].name.c_str(), fot[i0].family_members[i1].name.length() + 1);
            *GRADING << "Sending value of fot[" << i0 << "].family_members[" << i1 << "].name of type string - message: \"" << fot[i0].family_members[i1].name << "\", length: " << fot[i0].family_members[i1].name.length() + 1 << endl;

            string foti0family_membersi1ageStringRep = to_string(fot[i0].family_members[i1].age);
            *GRADING << "Converting " << fot[i0].family_members[i1].age << " of type int to string" << endl;

            RPCPROXYSOCKET->write(foti0family_membersi1ageStringRep.c_str(), foti0family_membersi1ageStringRep.length() + 1);
            *GRADING << "Sending value of fot[" << i0 << "].family_members[" << i1 << "].age in string form - message: \"" << fot[i0].family_members[i1].age << "\", length: " << foti0family_membersi1ageStringRep.length() + 1 << endl;

        }


    }


    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
}

void printFamily (FamilyOfThree fot) { 
    RPCPROXYSOCKET->write("printFamily", strlen("printFamily") + 1);
    *GRADING << "Invoking function printFamily remotely - message: \"printFamily\", length: " << strlen("printFamily") + 1 << endl;
    *GRADING << "Serializing parameter fot"<< endl;
    RPCPROXYSOCKET->write(fot.lastname.c_str(), fot.lastname.length() + 1);
    *GRADING << "Sending value of fot.lastname of type string - message: \"" << fot.lastname << "\", length: " << fot.lastname.length() + 1 << endl;

    
    for (int i0 = 0; i0 < 3; i0++) { 
        RPCPROXYSOCKET->write(fot.family_members[i0].name.c_str(), fot.family_members[i0].name.length() + 1);
        *GRADING << "Sending value of fot.family_members[" << i0 << "].name of type string - message: \"" << fot.family_members[i0].name << "\", length: " << fot.family_members[i0].name.length() + 1 << endl;

        string fotfamily_membersi0ageStringRep = to_string(fot.family_members[i0].age);
        *GRADING << "Converting " << fot.family_members[i0].age << " of type int to string" << endl;

        RPCPROXYSOCKET->write(fotfamily_membersi0ageStringRep.c_str(), fotfamily_membersi0ageStringRep.length() + 1);
        *GRADING << "Sending value of fot.family_members[" << i0 << "].age in string form - message: \"" << fot.family_members[i0].age << "\", length: " << fotfamily_membersi0ageStringRep.length() + 1 << endl;

    }


    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
}

void printNone () { 
    RPCPROXYSOCKET->write("printNone", strlen("printNone") + 1);
    *GRADING << "Invoking function printNone remotely - message: \"printNone\", length: " << strlen("printNone") + 1 << endl;
    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
}

void printOne (int one) { 
    RPCPROXYSOCKET->write("printOne", strlen("printOne") + 1);
    *GRADING << "Invoking function printOne remotely - message: \"printOne\", length: " << strlen("printOne") + 1 << endl;
    *GRADING << "Serializing parameter one"<< endl;
    string oneStringRep = to_string(one);
    *GRADING << "Converting " << one << " of type int to string" << endl;

    RPCPROXYSOCKET->write(oneStringRep.c_str(), oneStringRep.length() + 1);
    *GRADING << "Sending value of one in string form - message: \"" << one << "\", length: " << oneStringRep.length() + 1 << endl;

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
}

void printPerson (Person idil) { 
    RPCPROXYSOCKET->write("printPerson", strlen("printPerson") + 1);
    *GRADING << "Invoking function printPerson remotely - message: \"printPerson\", length: " << strlen("printPerson") + 1 << endl;
    *GRADING << "Serializing parameter idil"<< endl;
    RPCPROXYSOCKET->write(idil.name.c_str(), idil.name.length() + 1);
    *GRADING << "Sending value of idil.name of type string - message: \"" << idil.name << "\", length: " << idil.name.length() + 1 << endl;

    string idilageStringRep = to_string(idil.age);
    *GRADING << "Converting " << idil.age << " of type int to string" << endl;

    RPCPROXYSOCKET->write(idilageStringRep.c_str(), idilageStringRep.length() + 1);
    *GRADING << "Sending value of idil.age in string form - message: \"" << idil.age << "\", length: " << idilageStringRep.length() + 1 << endl;

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
}

void printPersons (Person persons[5]) { 
    RPCPROXYSOCKET->write("printPersons", strlen("printPersons") + 1);
    *GRADING << "Invoking function printPersons remotely - message: \"printPersons\", length: " << strlen("printPersons") + 1 << endl;
    *GRADING << "Serializing parameter persons"<< endl;
    
    for (int i0 = 0; i0 < 5; i0++) { 
        RPCPROXYSOCKET->write(persons[i0].name.c_str(), persons[i0].name.length() + 1);
        *GRADING << "Sending value of persons[" << i0 << "].name of type string - message: \"" << persons[i0].name << "\", length: " << persons[i0].name.length() + 1 << endl;

        string personsi0ageStringRep = to_string(persons[i0].age);
        *GRADING << "Converting " << persons[i0].age << " of type int to string" << endl;

        RPCPROXYSOCKET->write(personsi0ageStringRep.c_str(), personsi0ageStringRep.length() + 1);
        *GRADING << "Sending value of persons[" << i0 << "].age in string form - message: \"" << persons[i0].age << "\", length: " << personsi0ageStringRep.length() + 1 << endl;

    }


    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
}

void printPersonsOfPersons (Person people[5][4]) { 
    RPCPROXYSOCKET->write("printPersonsOfPersons", strlen("printPersonsOfPersons") + 1);
    *GRADING << "Invoking function printPersonsOfPersons remotely - message: \"printPersonsOfPersons\", length: " << strlen("printPersonsOfPersons") + 1 << endl;
    *GRADING << "Serializing parameter people"<< endl;
    
    for (int i0 = 0; i0 < 5; i0++) { 
        
        for (int i1 = 0; i1 < 4; i1++) { 
            RPCPROXYSOCKET->write(people[i0][i1].name.c_str(), people[i0][i1].name.length() + 1);
            *GRADING << "Sending value of people[" << i0 << "][" << i1 << "].name of type string - message: \"" << people[i0][i1].name << "\", length: " << people[i0][i1].name.length() + 1 << endl;

            string peoplei0i1ageStringRep = to_string(people[i0][i1].age);
            *GRADING << "Converting " << people[i0][i1].age << " of type int to string" << endl;

            RPCPROXYSOCKET->write(peoplei0i1ageStringRep.c_str(), peoplei0i1ageStringRep.length() + 1);
            *GRADING << "Sending value of people[" << i0 << "][" << i1 << "].age in string form - message: \"" << people[i0][i1].age << "\", length: " << peoplei0i1ageStringRep.length() + 1 << endl;

        }

    }


    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
}

void printRelative (Relative idils_sister) { 
    RPCPROXYSOCKET->write("printRelative", strlen("printRelative") + 1);
    *GRADING << "Invoking function printRelative remotely - message: \"printRelative\", length: " << strlen("printRelative") + 1 << endl;
    *GRADING << "Serializing parameter idils_sister"<< endl;
    RPCPROXYSOCKET->write(idils_sister.name.c_str(), idils_sister.name.length() + 1);
    *GRADING << "Sending value of idils_sister.name of type string - message: \"" << idils_sister.name << "\", length: " << idils_sister.name.length() + 1 << endl;

    string idils_sisterageStringRep = to_string(idils_sister.age);
    *GRADING << "Converting " << idils_sister.age << " of type int to string" << endl;

    RPCPROXYSOCKET->write(idils_sisterageStringRep.c_str(), idils_sisterageStringRep.length() + 1);
    *GRADING << "Sending value of idils_sister.age in string form - message: \"" << idils_sister.age << "\", length: " << idils_sisterageStringRep.length() + 1 << endl;

    RPCPROXYSOCKET->write(idils_sister.r.name.c_str(), idils_sister.r.name.length() + 1);
    *GRADING << "Sending value of idils_sister.r.name of type string - message: \"" << idils_sister.r.name << "\", length: " << idils_sister.r.name.length() + 1 << endl;

    string idils_sisterrageStringRep = to_string(idils_sister.r.age);
    *GRADING << "Converting " << idils_sister.r.age << " of type int to string" << endl;

    RPCPROXYSOCKET->write(idils_sisterrageStringRep.c_str(), idils_sisterrageStringRep.length() + 1);
    *GRADING << "Sending value of idils_sister.r.age in string form - message: \"" << idils_sister.r.age << "\", length: " << idils_sisterrageStringRep.length() + 1 << endl;

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
}

void printThis (string thisword) { 
    RPCPROXYSOCKET->write("printThis", strlen("printThis") + 1);
    *GRADING << "Invoking function printThis remotely - message: \"printThis\", length: " << strlen("printThis") + 1 << endl;
    *GRADING << "Serializing parameter thisword"<< endl;
    RPCPROXYSOCKET->write(thisword.c_str(), thisword.length() + 1);
    *GRADING << "Sending value of thisword of type string - message: \"" << thisword << "\", length: " << thisword.length() + 1 << endl;

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
}

void printTwo (float two) { 
    RPCPROXYSOCKET->write("printTwo", strlen("printTwo") + 1);
    *GRADING << "Invoking function printTwo remotely - message: \"printTwo\", length: " << strlen("printTwo") + 1 << endl;
    *GRADING << "Serializing parameter two"<< endl;
    string twoStringRep = to_string(two);
    *GRADING << "Converting " << two << " of type float to string" << endl;

    RPCPROXYSOCKET->write(twoStringRep.c_str(), twoStringRep.length() + 1);
    *GRADING << "Sending value of two in string form - message: \"" << two << "\", length: " << twoStringRep.length() + 1 << endl;

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
}

int returnAgeOfPerson (Person idil) { 
    RPCPROXYSOCKET->write("returnAgeOfPerson", strlen("returnAgeOfPerson") + 1);
    *GRADING << "Invoking function returnAgeOfPerson remotely - message: \"returnAgeOfPerson\", length: " << strlen("returnAgeOfPerson") + 1 << endl;
    *GRADING << "Serializing parameter idil"<< endl;
    RPCPROXYSOCKET->write(idil.name.c_str(), idil.name.length() + 1);
    *GRADING << "Sending value of idil.name of type string - message: \"" << idil.name << "\", length: " << idil.name.length() + 1 << endl;

    string idilageStringRep = to_string(idil.age);
    *GRADING << "Converting " << idil.age << " of type int to string" << endl;

    RPCPROXYSOCKET->write(idilageStringRep.c_str(), idilageStringRep.length() + 1);
    *GRADING << "Sending value of idil.age in string form - message: \"" << idil.age << "\", length: " << idilageStringRep.length() + 1 << endl;

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

int returnAgeOfRelativeOfPerson (Relative idils_sister) { 
    RPCPROXYSOCKET->write("returnAgeOfRelativeOfPerson", strlen("returnAgeOfRelativeOfPerson") + 1);
    *GRADING << "Invoking function returnAgeOfRelativeOfPerson remotely - message: \"returnAgeOfRelativeOfPerson\", length: " << strlen("returnAgeOfRelativeOfPerson") + 1 << endl;
    *GRADING << "Serializing parameter idils_sister"<< endl;
    RPCPROXYSOCKET->write(idils_sister.name.c_str(), idils_sister.name.length() + 1);
    *GRADING << "Sending value of idils_sister.name of type string - message: \"" << idils_sister.name << "\", length: " << idils_sister.name.length() + 1 << endl;

    string idils_sisterageStringRep = to_string(idils_sister.age);
    *GRADING << "Converting " << idils_sister.age << " of type int to string" << endl;

    RPCPROXYSOCKET->write(idils_sisterageStringRep.c_str(), idils_sisterageStringRep.length() + 1);
    *GRADING << "Sending value of idils_sister.age in string form - message: \"" << idils_sister.age << "\", length: " << idils_sisterageStringRep.length() + 1 << endl;

    RPCPROXYSOCKET->write(idils_sister.r.name.c_str(), idils_sister.r.name.length() + 1);
    *GRADING << "Sending value of idils_sister.r.name of type string - message: \"" << idils_sister.r.name << "\", length: " << idils_sister.r.name.length() + 1 << endl;

    string idils_sisterrageStringRep = to_string(idils_sister.r.age);
    *GRADING << "Converting " << idils_sister.r.age << " of type int to string" << endl;

    RPCPROXYSOCKET->write(idils_sisterrageStringRep.c_str(), idils_sisterrageStringRep.length() + 1);
    *GRADING << "Sending value of idils_sister.r.age in string form - message: \"" << idils_sister.r.age << "\", length: " << idils_sisterrageStringRep.length() + 1 << endl;

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

int returnAverageAgeOfFamilies (FamilyOfThree fot[5]) { 
    RPCPROXYSOCKET->write("returnAverageAgeOfFamilies", strlen("returnAverageAgeOfFamilies") + 1);
    *GRADING << "Invoking function returnAverageAgeOfFamilies remotely - message: \"returnAverageAgeOfFamilies\", length: " << strlen("returnAverageAgeOfFamilies") + 1 << endl;
    *GRADING << "Serializing parameter fot"<< endl;
    
    for (int i0 = 0; i0 < 5; i0++) { 
        RPCPROXYSOCKET->write(fot[i0].lastname.c_str(), fot[i0].lastname.length() + 1);
        *GRADING << "Sending value of fot[" << i0 << "].lastname of type string - message: \"" << fot[i0].lastname << "\", length: " << fot[i0].lastname.length() + 1 << endl;

        
        for (int i1 = 0; i1 < 3; i1++) { 
            RPCPROXYSOCKET->write(fot[i0].family_members[i1].name.c_str(), fot[i0].family_members[i1].name.length() + 1);
            *GRADING << "Sending value of fot[" << i0 << "].family_members[" << i1 << "].name of type string - message: \"" << fot[i0].family_members[i1].name << "\", length: " << fot[i0].family_members[i1].name.length() + 1 << endl;

            string foti0family_membersi1ageStringRep = to_string(fot[i0].family_members[i1].age);
            *GRADING << "Converting " << fot[i0].family_members[i1].age << " of type int to string" << endl;

            RPCPROXYSOCKET->write(foti0family_membersi1ageStringRep.c_str(), foti0family_membersi1ageStringRep.length() + 1);
            *GRADING << "Sending value of fot[" << i0 << "].family_members[" << i1 << "].age in string form - message: \"" << fot[i0].family_members[i1].age << "\", length: " << foti0family_membersi1ageStringRep.length() + 1 << endl;

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

int returnAverageAgeOfFamily (FamilyOfThree fot) { 
    RPCPROXYSOCKET->write("returnAverageAgeOfFamily", strlen("returnAverageAgeOfFamily") + 1);
    *GRADING << "Invoking function returnAverageAgeOfFamily remotely - message: \"returnAverageAgeOfFamily\", length: " << strlen("returnAverageAgeOfFamily") + 1 << endl;
    *GRADING << "Serializing parameter fot"<< endl;
    RPCPROXYSOCKET->write(fot.lastname.c_str(), fot.lastname.length() + 1);
    *GRADING << "Sending value of fot.lastname of type string - message: \"" << fot.lastname << "\", length: " << fot.lastname.length() + 1 << endl;

    
    for (int i0 = 0; i0 < 3; i0++) { 
        RPCPROXYSOCKET->write(fot.family_members[i0].name.c_str(), fot.family_members[i0].name.length() + 1);
        *GRADING << "Sending value of fot.family_members[" << i0 << "].name of type string - message: \"" << fot.family_members[i0].name << "\", length: " << fot.family_members[i0].name.length() + 1 << endl;

        string fotfamily_membersi0ageStringRep = to_string(fot.family_members[i0].age);
        *GRADING << "Converting " << fot.family_members[i0].age << " of type int to string" << endl;

        RPCPROXYSOCKET->write(fotfamily_membersi0ageStringRep.c_str(), fotfamily_membersi0ageStringRep.length() + 1);
        *GRADING << "Sending value of fot.family_members[" << i0 << "].age in string form - message: \"" << fot.family_members[i0].age << "\", length: " << fotfamily_membersi0ageStringRep.length() + 1 << endl;

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

int returnAverageAgeOfPeople (Person people[5][4]) { 
    RPCPROXYSOCKET->write("returnAverageAgeOfPeople", strlen("returnAverageAgeOfPeople") + 1);
    *GRADING << "Invoking function returnAverageAgeOfPeople remotely - message: \"returnAverageAgeOfPeople\", length: " << strlen("returnAverageAgeOfPeople") + 1 << endl;
    *GRADING << "Serializing parameter people"<< endl;
    
    for (int i0 = 0; i0 < 5; i0++) { 
        
        for (int i1 = 0; i1 < 4; i1++) { 
            RPCPROXYSOCKET->write(people[i0][i1].name.c_str(), people[i0][i1].name.length() + 1);
            *GRADING << "Sending value of people[" << i0 << "][" << i1 << "].name of type string - message: \"" << people[i0][i1].name << "\", length: " << people[i0][i1].name.length() + 1 << endl;

            string peoplei0i1ageStringRep = to_string(people[i0][i1].age);
            *GRADING << "Converting " << people[i0][i1].age << " of type int to string" << endl;

            RPCPROXYSOCKET->write(peoplei0i1ageStringRep.c_str(), peoplei0i1ageStringRep.length() + 1);
            *GRADING << "Sending value of people[" << i0 << "][" << i1 << "].age in string form - message: \"" << people[i0][i1].age << "\", length: " << peoplei0i1ageStringRep.length() + 1 << endl;

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

int returnAverageAgeOfPersons (Person persons[5]) { 
    RPCPROXYSOCKET->write("returnAverageAgeOfPersons", strlen("returnAverageAgeOfPersons") + 1);
    *GRADING << "Invoking function returnAverageAgeOfPersons remotely - message: \"returnAverageAgeOfPersons\", length: " << strlen("returnAverageAgeOfPersons") + 1 << endl;
    *GRADING << "Serializing parameter persons"<< endl;
    
    for (int i0 = 0; i0 < 5; i0++) { 
        RPCPROXYSOCKET->write(persons[i0].name.c_str(), persons[i0].name.length() + 1);
        *GRADING << "Sending value of persons[" << i0 << "].name of type string - message: \"" << persons[i0].name << "\", length: " << persons[i0].name.length() + 1 << endl;

        string personsi0ageStringRep = to_string(persons[i0].age);
        *GRADING << "Converting " << persons[i0].age << " of type int to string" << endl;

        RPCPROXYSOCKET->write(personsi0ageStringRep.c_str(), personsi0ageStringRep.length() + 1);
        *GRADING << "Sending value of persons[" << i0 << "].age in string form - message: \"" << persons[i0].age << "\", length: " << personsi0ageStringRep.length() + 1 << endl;

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

int returnInputFloat (float input) { 
    RPCPROXYSOCKET->write("returnInputFloat", strlen("returnInputFloat") + 1);
    *GRADING << "Invoking function returnInputFloat remotely - message: \"returnInputFloat\", length: " << strlen("returnInputFloat") + 1 << endl;
    *GRADING << "Serializing parameter input"<< endl;
    string inputStringRep = to_string(input);
    *GRADING << "Converting " << input << " of type float to string" << endl;

    RPCPROXYSOCKET->write(inputStringRep.c_str(), inputStringRep.length() + 1);
    *GRADING << "Sending value of input in string form - message: \"" << input << "\", length: " << inputStringRep.length() + 1 << endl;

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

int returnInputInt (int input) { 
    RPCPROXYSOCKET->write("returnInputInt", strlen("returnInputInt") + 1);
    *GRADING << "Invoking function returnInputInt remotely - message: \"returnInputInt\", length: " << strlen("returnInputInt") + 1 << endl;
    *GRADING << "Serializing parameter input"<< endl;
    string inputStringRep = to_string(input);
    *GRADING << "Converting " << input << " of type int to string" << endl;

    RPCPROXYSOCKET->write(inputStringRep.c_str(), inputStringRep.length() + 1);
    *GRADING << "Sending value of input in string form - message: \"" << input << "\", length: " << inputStringRep.length() + 1 << endl;

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

int returnInputString (string input) { 
    RPCPROXYSOCKET->write("returnInputString", strlen("returnInputString") + 1);
    *GRADING << "Invoking function returnInputString remotely - message: \"returnInputString\", length: " << strlen("returnInputString") + 1 << endl;
    *GRADING << "Serializing parameter input"<< endl;
    RPCPROXYSOCKET->write(input.c_str(), input.length() + 1);
    *GRADING << "Sending value of input of type string - message: \"" << input << "\", length: " << input.length() + 1 << endl;

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

Person returnOldestAverageFamily (FamilyOfThree fot[5]) { 
    RPCPROXYSOCKET->write("returnOldestAverageFamily", strlen("returnOldestAverageFamily") + 1);
    *GRADING << "Invoking function returnOldestAverageFamily remotely - message: \"returnOldestAverageFamily\", length: " << strlen("returnOldestAverageFamily") + 1 << endl;
    *GRADING << "Serializing parameter fot"<< endl;
    
    for (int i0 = 0; i0 < 5; i0++) { 
        RPCPROXYSOCKET->write(fot[i0].lastname.c_str(), fot[i0].lastname.length() + 1);
        *GRADING << "Sending value of fot[" << i0 << "].lastname of type string - message: \"" << fot[i0].lastname << "\", length: " << fot[i0].lastname.length() + 1 << endl;

        
        for (int i1 = 0; i1 < 3; i1++) { 
            RPCPROXYSOCKET->write(fot[i0].family_members[i1].name.c_str(), fot[i0].family_members[i1].name.length() + 1);
            *GRADING << "Sending value of fot[" << i0 << "].family_members[" << i1 << "].name of type string - message: \"" << fot[i0].family_members[i1].name << "\", length: " << fot[i0].family_members[i1].name.length() + 1 << endl;

            string foti0family_membersi1ageStringRep = to_string(fot[i0].family_members[i1].age);
            *GRADING << "Converting " << fot[i0].family_members[i1].age << " of type int to string" << endl;

            RPCPROXYSOCKET->write(foti0family_membersi1ageStringRep.c_str(), foti0family_membersi1ageStringRep.length() + 1);
            *GRADING << "Sending value of fot[" << i0 << "].family_members[" << i1 << "].age in string form - message: \"" << fot[i0].family_members[i1].age << "\", length: " << foti0family_membersi1ageStringRep.length() + 1 << endl;

        }


    }


    Person retVal;
    retVal.name = getStringFromStream();
    *GRADING << "Received value for retVal.name of type string - message: \"" << retVal.name << "\", length: " << retVal.name.length() + 1 << endl;

    retVal.age = stoi(getStringFromStream());
    *GRADING << "Received value " << retVal.age << " (of type int in string form) for retVal.age" << endl;

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
    
    return retVal;
}

FamilyOfThree returnOldestFamily (FamilyOfThree families[5]) { 
    RPCPROXYSOCKET->write("returnOldestFamily", strlen("returnOldestFamily") + 1);
    *GRADING << "Invoking function returnOldestFamily remotely - message: \"returnOldestFamily\", length: " << strlen("returnOldestFamily") + 1 << endl;
    *GRADING << "Serializing parameter families"<< endl;
    
    for (int i0 = 0; i0 < 5; i0++) { 
        RPCPROXYSOCKET->write(families[i0].lastname.c_str(), families[i0].lastname.length() + 1);
        *GRADING << "Sending value of families[" << i0 << "].lastname of type string - message: \"" << families[i0].lastname << "\", length: " << families[i0].lastname.length() + 1 << endl;

        
        for (int i1 = 0; i1 < 3; i1++) { 
            RPCPROXYSOCKET->write(families[i0].family_members[i1].name.c_str(), families[i0].family_members[i1].name.length() + 1);
            *GRADING << "Sending value of families[" << i0 << "].family_members[" << i1 << "].name of type string - message: \"" << families[i0].family_members[i1].name << "\", length: " << families[i0].family_members[i1].name.length() + 1 << endl;

            string familiesi0family_membersi1ageStringRep = to_string(families[i0].family_members[i1].age);
            *GRADING << "Converting " << families[i0].family_members[i1].age << " of type int to string" << endl;

            RPCPROXYSOCKET->write(familiesi0family_membersi1ageStringRep.c_str(), familiesi0family_membersi1ageStringRep.length() + 1);
            *GRADING << "Sending value of families[" << i0 << "].family_members[" << i1 << "].age in string form - message: \"" << families[i0].family_members[i1].age << "\", length: " << familiesi0family_membersi1ageStringRep.length() + 1 << endl;

        }


    }


    FamilyOfThree retVal;
    retVal.lastname = getStringFromStream();
    *GRADING << "Received value for retVal.lastname of type string - message: \"" << retVal.lastname << "\", length: " << retVal.lastname.length() + 1 << endl;

    
    for (int i0 = 0; i0 < 3; i0++) { 
        retVal.family_members[i0].name = getStringFromStream();
        *GRADING << "Received value for retVal.family_members[" << i0 << "].name of type string - message: \"" << retVal.family_members[i0].name << "\", length: " << retVal.family_members[i0].name.length() + 1 << endl;

        retVal.family_members[i0].age = stoi(getStringFromStream());
        *GRADING << "Received value " << retVal.family_members[i0].age << " (of type int in string form) for retVal.family_members[" << i0 << "].age" << endl;

    }


    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
    
    return retVal;
}

Person returnOldestMember (FamilyOfThree fot) { 
    RPCPROXYSOCKET->write("returnOldestMember", strlen("returnOldestMember") + 1);
    *GRADING << "Invoking function returnOldestMember remotely - message: \"returnOldestMember\", length: " << strlen("returnOldestMember") + 1 << endl;
    *GRADING << "Serializing parameter fot"<< endl;
    RPCPROXYSOCKET->write(fot.lastname.c_str(), fot.lastname.length() + 1);
    *GRADING << "Sending value of fot.lastname of type string - message: \"" << fot.lastname << "\", length: " << fot.lastname.length() + 1 << endl;

    
    for (int i0 = 0; i0 < 3; i0++) { 
        RPCPROXYSOCKET->write(fot.family_members[i0].name.c_str(), fot.family_members[i0].name.length() + 1);
        *GRADING << "Sending value of fot.family_members[" << i0 << "].name of type string - message: \"" << fot.family_members[i0].name << "\", length: " << fot.family_members[i0].name.length() + 1 << endl;

        string fotfamily_membersi0ageStringRep = to_string(fot.family_members[i0].age);
        *GRADING << "Converting " << fot.family_members[i0].age << " of type int to string" << endl;

        RPCPROXYSOCKET->write(fotfamily_membersi0ageStringRep.c_str(), fotfamily_membersi0ageStringRep.length() + 1);
        *GRADING << "Sending value of fot.family_members[" << i0 << "].age in string form - message: \"" << fot.family_members[i0].age << "\", length: " << fotfamily_membersi0ageStringRep.length() + 1 << endl;

    }


    Person retVal;
    retVal.name = getStringFromStream();
    *GRADING << "Received value for retVal.name of type string - message: \"" << retVal.name << "\", length: " << retVal.name.length() + 1 << endl;

    retVal.age = stoi(getStringFromStream());
    *GRADING << "Received value " << retVal.age << " (of type int in string form) for retVal.age" << endl;

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
    
    return retVal;
}

Person returnRelativeAYearOlder (Relative idils_sister) { 
    RPCPROXYSOCKET->write("returnRelativeAYearOlder", strlen("returnRelativeAYearOlder") + 1);
    *GRADING << "Invoking function returnRelativeAYearOlder remotely - message: \"returnRelativeAYearOlder\", length: " << strlen("returnRelativeAYearOlder") + 1 << endl;
    *GRADING << "Serializing parameter idils_sister"<< endl;
    RPCPROXYSOCKET->write(idils_sister.name.c_str(), idils_sister.name.length() + 1);
    *GRADING << "Sending value of idils_sister.name of type string - message: \"" << idils_sister.name << "\", length: " << idils_sister.name.length() + 1 << endl;

    string idils_sisterageStringRep = to_string(idils_sister.age);
    *GRADING << "Converting " << idils_sister.age << " of type int to string" << endl;

    RPCPROXYSOCKET->write(idils_sisterageStringRep.c_str(), idils_sisterageStringRep.length() + 1);
    *GRADING << "Sending value of idils_sister.age in string form - message: \"" << idils_sister.age << "\", length: " << idils_sisterageStringRep.length() + 1 << endl;

    RPCPROXYSOCKET->write(idils_sister.r.name.c_str(), idils_sister.r.name.length() + 1);
    *GRADING << "Sending value of idils_sister.r.name of type string - message: \"" << idils_sister.r.name << "\", length: " << idils_sister.r.name.length() + 1 << endl;

    string idils_sisterrageStringRep = to_string(idils_sister.r.age);
    *GRADING << "Converting " << idils_sister.r.age << " of type int to string" << endl;

    RPCPROXYSOCKET->write(idils_sisterrageStringRep.c_str(), idils_sisterrageStringRep.length() + 1);
    *GRADING << "Sending value of idils_sister.r.age in string form - message: \"" << idils_sister.r.age << "\", length: " << idils_sisterrageStringRep.length() + 1 << endl;

    Person retVal;
    retVal.name = getStringFromStream();
    *GRADING << "Received value for retVal.name of type string - message: \"" << retVal.name << "\", length: " << retVal.name.length() + 1 << endl;

    retVal.age = stoi(getStringFromStream());
    *GRADING << "Received value " << retVal.age << " (of type int in string form) for retVal.age" << endl;

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
    
    return retVal;
}

int returnTwo () { 
    RPCPROXYSOCKET->write("returnTwo", strlen("returnTwo") + 1);
    *GRADING << "Invoking function returnTwo remotely - message: \"returnTwo\", length: " << strlen("returnTwo") + 1 << endl;
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

Person returnYoungestAveragePeople (Person people[5][4]) { 
    RPCPROXYSOCKET->write("returnYoungestAveragePeople", strlen("returnYoungestAveragePeople") + 1);
    *GRADING << "Invoking function returnYoungestAveragePeople remotely - message: \"returnYoungestAveragePeople\", length: " << strlen("returnYoungestAveragePeople") + 1 << endl;
    *GRADING << "Serializing parameter people"<< endl;
    
    for (int i0 = 0; i0 < 5; i0++) { 
        
        for (int i1 = 0; i1 < 4; i1++) { 
            RPCPROXYSOCKET->write(people[i0][i1].name.c_str(), people[i0][i1].name.length() + 1);
            *GRADING << "Sending value of people[" << i0 << "][" << i1 << "].name of type string - message: \"" << people[i0][i1].name << "\", length: " << people[i0][i1].name.length() + 1 << endl;

            string peoplei0i1ageStringRep = to_string(people[i0][i1].age);
            *GRADING << "Converting " << people[i0][i1].age << " of type int to string" << endl;

            RPCPROXYSOCKET->write(peoplei0i1ageStringRep.c_str(), peoplei0i1ageStringRep.length() + 1);
            *GRADING << "Sending value of people[" << i0 << "][" << i1 << "].age in string form - message: \"" << people[i0][i1].age << "\", length: " << peoplei0i1ageStringRep.length() + 1 << endl;

        }

    }


    Person retVal;
    retVal.name = getStringFromStream();
    *GRADING << "Received value for retVal.name of type string - message: \"" << retVal.name << "\", length: " << retVal.name.length() + 1 << endl;

    retVal.age = stoi(getStringFromStream());
    *GRADING << "Received value " << retVal.age << " (of type int in string form) for retVal.age" << endl;

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
    
    return retVal;
}

Person returnYoungestMember (Person persons[5]) { 
    RPCPROXYSOCKET->write("returnYoungestMember", strlen("returnYoungestMember") + 1);
    *GRADING << "Invoking function returnYoungestMember remotely - message: \"returnYoungestMember\", length: " << strlen("returnYoungestMember") + 1 << endl;
    *GRADING << "Serializing parameter persons"<< endl;
    
    for (int i0 = 0; i0 < 5; i0++) { 
        RPCPROXYSOCKET->write(persons[i0].name.c_str(), persons[i0].name.length() + 1);
        *GRADING << "Sending value of persons[" << i0 << "].name of type string - message: \"" << persons[i0].name << "\", length: " << persons[i0].name.length() + 1 << endl;

        string personsi0ageStringRep = to_string(persons[i0].age);
        *GRADING << "Converting " << persons[i0].age << " of type int to string" << endl;

        RPCPROXYSOCKET->write(personsi0ageStringRep.c_str(), personsi0ageStringRep.length() + 1);
        *GRADING << "Sending value of persons[" << i0 << "].age in string form - message: \"" << persons[i0].age << "\", length: " << personsi0ageStringRep.length() + 1 << endl;

    }


    Person retVal;
    retVal.name = getStringFromStream();
    *GRADING << "Received value for retVal.name of type string - message: \"" << retVal.name << "\", length: " << retVal.name.length() + 1 << endl;

    retVal.age = stoi(getStringFromStream());
    *GRADING << "Received value " << retVal.age << " (of type int in string form) for retVal.age" << endl;

    char readBuffer[4];
    RPCPROXYSOCKET->read(readBuffer, 4);
    if (strncmp(readBuffer, "DONE", 4) != 0) {
        throw C150Exception("error");
    }
    *GRADING << "Returned successfully from RPC"<< endl;
    
    return retVal;
}

string sReturnAgeOfPerson (Person idil) { 
    RPCPROXYSOCKET->write("sReturnAgeOfPerson", strlen("sReturnAgeOfPerson") + 1);
    *GRADING << "Invoking function sReturnAgeOfPerson remotely - message: \"sReturnAgeOfPerson\", length: " << strlen("sReturnAgeOfPerson") + 1 << endl;
    *GRADING << "Serializing parameter idil"<< endl;
    RPCPROXYSOCKET->write(idil.name.c_str(), idil.name.length() + 1);
    *GRADING << "Sending value of idil.name of type string - message: \"" << idil.name << "\", length: " << idil.name.length() + 1 << endl;

    string idilageStringRep = to_string(idil.age);
    *GRADING << "Converting " << idil.age << " of type int to string" << endl;

    RPCPROXYSOCKET->write(idilageStringRep.c_str(), idilageStringRep.length() + 1);
    *GRADING << "Sending value of idil.age in string form - message: \"" << idil.age << "\", length: " << idilageStringRep.length() + 1 << endl;

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

string sReturnAgeOfRelativeOfPerson (Relative idils_sister) { 
    RPCPROXYSOCKET->write("sReturnAgeOfRelativeOfPerson", strlen("sReturnAgeOfRelativeOfPerson") + 1);
    *GRADING << "Invoking function sReturnAgeOfRelativeOfPerson remotely - message: \"sReturnAgeOfRelativeOfPerson\", length: " << strlen("sReturnAgeOfRelativeOfPerson") + 1 << endl;
    *GRADING << "Serializing parameter idils_sister"<< endl;
    RPCPROXYSOCKET->write(idils_sister.name.c_str(), idils_sister.name.length() + 1);
    *GRADING << "Sending value of idils_sister.name of type string - message: \"" << idils_sister.name << "\", length: " << idils_sister.name.length() + 1 << endl;

    string idils_sisterageStringRep = to_string(idils_sister.age);
    *GRADING << "Converting " << idils_sister.age << " of type int to string" << endl;

    RPCPROXYSOCKET->write(idils_sisterageStringRep.c_str(), idils_sisterageStringRep.length() + 1);
    *GRADING << "Sending value of idils_sister.age in string form - message: \"" << idils_sister.age << "\", length: " << idils_sisterageStringRep.length() + 1 << endl;

    RPCPROXYSOCKET->write(idils_sister.r.name.c_str(), idils_sister.r.name.length() + 1);
    *GRADING << "Sending value of idils_sister.r.name of type string - message: \"" << idils_sister.r.name << "\", length: " << idils_sister.r.name.length() + 1 << endl;

    string idils_sisterrageStringRep = to_string(idils_sister.r.age);
    *GRADING << "Converting " << idils_sister.r.age << " of type int to string" << endl;

    RPCPROXYSOCKET->write(idils_sisterrageStringRep.c_str(), idils_sisterrageStringRep.length() + 1);
    *GRADING << "Sending value of idils_sister.r.age in string form - message: \"" << idils_sister.r.age << "\", length: " << idils_sisterrageStringRep.length() + 1 << endl;

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

string sReturnAverageAgeOfFamilies (FamilyOfThree fot[5]) { 
    RPCPROXYSOCKET->write("sReturnAverageAgeOfFamilies", strlen("sReturnAverageAgeOfFamilies") + 1);
    *GRADING << "Invoking function sReturnAverageAgeOfFamilies remotely - message: \"sReturnAverageAgeOfFamilies\", length: " << strlen("sReturnAverageAgeOfFamilies") + 1 << endl;
    *GRADING << "Serializing parameter fot"<< endl;
    
    for (int i0 = 0; i0 < 5; i0++) { 
        RPCPROXYSOCKET->write(fot[i0].lastname.c_str(), fot[i0].lastname.length() + 1);
        *GRADING << "Sending value of fot[" << i0 << "].lastname of type string - message: \"" << fot[i0].lastname << "\", length: " << fot[i0].lastname.length() + 1 << endl;

        
        for (int i1 = 0; i1 < 3; i1++) { 
            RPCPROXYSOCKET->write(fot[i0].family_members[i1].name.c_str(), fot[i0].family_members[i1].name.length() + 1);
            *GRADING << "Sending value of fot[" << i0 << "].family_members[" << i1 << "].name of type string - message: \"" << fot[i0].family_members[i1].name << "\", length: " << fot[i0].family_members[i1].name.length() + 1 << endl;

            string foti0family_membersi1ageStringRep = to_string(fot[i0].family_members[i1].age);
            *GRADING << "Converting " << fot[i0].family_members[i1].age << " of type int to string" << endl;

            RPCPROXYSOCKET->write(foti0family_membersi1ageStringRep.c_str(), foti0family_membersi1ageStringRep.length() + 1);
            *GRADING << "Sending value of fot[" << i0 << "].family_members[" << i1 << "].age in string form - message: \"" << fot[i0].family_members[i1].age << "\", length: " << foti0family_membersi1ageStringRep.length() + 1 << endl;

        }


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

string sReturnAverageAgeOfFamily (FamilyOfThree fot) { 
    RPCPROXYSOCKET->write("sReturnAverageAgeOfFamily", strlen("sReturnAverageAgeOfFamily") + 1);
    *GRADING << "Invoking function sReturnAverageAgeOfFamily remotely - message: \"sReturnAverageAgeOfFamily\", length: " << strlen("sReturnAverageAgeOfFamily") + 1 << endl;
    *GRADING << "Serializing parameter fot"<< endl;
    RPCPROXYSOCKET->write(fot.lastname.c_str(), fot.lastname.length() + 1);
    *GRADING << "Sending value of fot.lastname of type string - message: \"" << fot.lastname << "\", length: " << fot.lastname.length() + 1 << endl;

    
    for (int i0 = 0; i0 < 3; i0++) { 
        RPCPROXYSOCKET->write(fot.family_members[i0].name.c_str(), fot.family_members[i0].name.length() + 1);
        *GRADING << "Sending value of fot.family_members[" << i0 << "].name of type string - message: \"" << fot.family_members[i0].name << "\", length: " << fot.family_members[i0].name.length() + 1 << endl;

        string fotfamily_membersi0ageStringRep = to_string(fot.family_members[i0].age);
        *GRADING << "Converting " << fot.family_members[i0].age << " of type int to string" << endl;

        RPCPROXYSOCKET->write(fotfamily_membersi0ageStringRep.c_str(), fotfamily_membersi0ageStringRep.length() + 1);
        *GRADING << "Sending value of fot.family_members[" << i0 << "].age in string form - message: \"" << fot.family_members[i0].age << "\", length: " << fotfamily_membersi0ageStringRep.length() + 1 << endl;

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

string sReturnAverageAgeOfPeople (Person people[5][4]) { 
    RPCPROXYSOCKET->write("sReturnAverageAgeOfPeople", strlen("sReturnAverageAgeOfPeople") + 1);
    *GRADING << "Invoking function sReturnAverageAgeOfPeople remotely - message: \"sReturnAverageAgeOfPeople\", length: " << strlen("sReturnAverageAgeOfPeople") + 1 << endl;
    *GRADING << "Serializing parameter people"<< endl;
    
    for (int i0 = 0; i0 < 5; i0++) { 
        
        for (int i1 = 0; i1 < 4; i1++) { 
            RPCPROXYSOCKET->write(people[i0][i1].name.c_str(), people[i0][i1].name.length() + 1);
            *GRADING << "Sending value of people[" << i0 << "][" << i1 << "].name of type string - message: \"" << people[i0][i1].name << "\", length: " << people[i0][i1].name.length() + 1 << endl;

            string peoplei0i1ageStringRep = to_string(people[i0][i1].age);
            *GRADING << "Converting " << people[i0][i1].age << " of type int to string" << endl;

            RPCPROXYSOCKET->write(peoplei0i1ageStringRep.c_str(), peoplei0i1ageStringRep.length() + 1);
            *GRADING << "Sending value of people[" << i0 << "][" << i1 << "].age in string form - message: \"" << people[i0][i1].age << "\", length: " << peoplei0i1ageStringRep.length() + 1 << endl;

        }

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

string sReturnAverageAgeOfPersons (Person persons[5]) { 
    RPCPROXYSOCKET->write("sReturnAverageAgeOfPersons", strlen("sReturnAverageAgeOfPersons") + 1);
    *GRADING << "Invoking function sReturnAverageAgeOfPersons remotely - message: \"sReturnAverageAgeOfPersons\", length: " << strlen("sReturnAverageAgeOfPersons") + 1 << endl;
    *GRADING << "Serializing parameter persons"<< endl;
    
    for (int i0 = 0; i0 < 5; i0++) { 
        RPCPROXYSOCKET->write(persons[i0].name.c_str(), persons[i0].name.length() + 1);
        *GRADING << "Sending value of persons[" << i0 << "].name of type string - message: \"" << persons[i0].name << "\", length: " << persons[i0].name.length() + 1 << endl;

        string personsi0ageStringRep = to_string(persons[i0].age);
        *GRADING << "Converting " << persons[i0].age << " of type int to string" << endl;

        RPCPROXYSOCKET->write(personsi0ageStringRep.c_str(), personsi0ageStringRep.length() + 1);
        *GRADING << "Sending value of persons[" << i0 << "].age in string form - message: \"" << persons[i0].age << "\", length: " << personsi0ageStringRep.length() + 1 << endl;

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

string sReturnInputFloat (float input) { 
    RPCPROXYSOCKET->write("sReturnInputFloat", strlen("sReturnInputFloat") + 1);
    *GRADING << "Invoking function sReturnInputFloat remotely - message: \"sReturnInputFloat\", length: " << strlen("sReturnInputFloat") + 1 << endl;
    *GRADING << "Serializing parameter input"<< endl;
    string inputStringRep = to_string(input);
    *GRADING << "Converting " << input << " of type float to string" << endl;

    RPCPROXYSOCKET->write(inputStringRep.c_str(), inputStringRep.length() + 1);
    *GRADING << "Sending value of input in string form - message: \"" << input << "\", length: " << inputStringRep.length() + 1 << endl;

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

string sReturnInputInt (int input) { 
    RPCPROXYSOCKET->write("sReturnInputInt", strlen("sReturnInputInt") + 1);
    *GRADING << "Invoking function sReturnInputInt remotely - message: \"sReturnInputInt\", length: " << strlen("sReturnInputInt") + 1 << endl;
    *GRADING << "Serializing parameter input"<< endl;
    string inputStringRep = to_string(input);
    *GRADING << "Converting " << input << " of type int to string" << endl;

    RPCPROXYSOCKET->write(inputStringRep.c_str(), inputStringRep.length() + 1);
    *GRADING << "Sending value of input in string form - message: \"" << input << "\", length: " << inputStringRep.length() + 1 << endl;

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

string sReturnInputString (string input) { 
    RPCPROXYSOCKET->write("sReturnInputString", strlen("sReturnInputString") + 1);
    *GRADING << "Invoking function sReturnInputString remotely - message: \"sReturnInputString\", length: " << strlen("sReturnInputString") + 1 << endl;
    *GRADING << "Serializing parameter input"<< endl;
    RPCPROXYSOCKET->write(input.c_str(), input.length() + 1);
    *GRADING << "Sending value of input of type string - message: \"" << input << "\", length: " << input.length() + 1 << endl;

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

string sReturnTwo () { 
    RPCPROXYSOCKET->write("sReturnTwo", strlen("sReturnTwo") + 1);
    *GRADING << "Invoking function sReturnTwo remotely - message: \"sReturnTwo\", length: " << strlen("sReturnTwo") + 1 << endl;
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
