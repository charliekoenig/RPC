#include "rpcstubhelper.h"
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

#include "idils-crazy-tests.idl"
#include "c150grading.h"

using namespace C150NETWORK;

string getStringFromStream();


void __fReturnAgeOfPerson () { 
    char doneBuffer[5] = "DONE";
    Person idil;
    idil.name = getStringFromStream();
    *GRADING << "Received value for idil.name of type string - message: \"" << idil.name << "\", length: " << idil.name.length() + 1 << endl;

    idil.age = stoi(getStringFromStream());
    *GRADING << "Received value " << idil.age << " (of type int in string form) for idil.age" << endl;

    *GRADING << "Function fReturnAgeOfPerson invoked locally" << endl;
    float retVal = fReturnAgeOfPerson(idil);
    string retValStringRep = to_string(retVal);
    *GRADING << "Converting " << retVal << " of type float to string" << endl;

    RPCSTUBSOCKET->write(retValStringRep.c_str(), retValStringRep.length() + 1);
    *GRADING << "Sending value of retVal in string form - message: \"" << retVal << "\", length: " << retValStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function fReturnAgeOfPerson invocation done"<< endl;
}

void __fReturnAgeOfRelativeOfPerson () { 
    char doneBuffer[5] = "DONE";
    Relative idils_sister;
    idils_sister.name = getStringFromStream();
    *GRADING << "Received value for idils_sister.name of type string - message: \"" << idils_sister.name << "\", length: " << idils_sister.name.length() + 1 << endl;

    idils_sister.age = stoi(getStringFromStream());
    *GRADING << "Received value " << idils_sister.age << " (of type int in string form) for idils_sister.age" << endl;

    idils_sister.r.name = getStringFromStream();
    *GRADING << "Received value for idils_sister.r.name of type string - message: \"" << idils_sister.r.name << "\", length: " << idils_sister.r.name.length() + 1 << endl;

    idils_sister.r.age = stoi(getStringFromStream());
    *GRADING << "Received value " << idils_sister.r.age << " (of type int in string form) for idils_sister.r.age" << endl;

    *GRADING << "Function fReturnAgeOfRelativeOfPerson invoked locally" << endl;
    float retVal = fReturnAgeOfRelativeOfPerson(idils_sister);
    string retValStringRep = to_string(retVal);
    *GRADING << "Converting " << retVal << " of type float to string" << endl;

    RPCSTUBSOCKET->write(retValStringRep.c_str(), retValStringRep.length() + 1);
    *GRADING << "Sending value of retVal in string form - message: \"" << retVal << "\", length: " << retValStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function fReturnAgeOfRelativeOfPerson invocation done"<< endl;
}

void __fReturnAverageAgeOfFamilies () { 
    char doneBuffer[5] = "DONE";
    FamilyOfThree fot[5];
    
    for (int i0 = 0; i0 < 5; i0++) { 
        fot[i0].lastname = getStringFromStream();
        *GRADING << "Received value for fot[" << i0 << "].lastname of type string - message: \"" << fot[i0].lastname << "\", length: " << fot[i0].lastname.length() + 1 << endl;

        
        for (int i1 = 0; i1 < 3; i1++) { 
            fot[i0].family_members[i1].name = getStringFromStream();
            *GRADING << "Received value for fot[" << i0 << "].family_members[" << i1 << "].name of type string - message: \"" << fot[i0].family_members[i1].name << "\", length: " << fot[i0].family_members[i1].name.length() + 1 << endl;

            fot[i0].family_members[i1].age = stoi(getStringFromStream());
            *GRADING << "Received value " << fot[i0].family_members[i1].age << " (of type int in string form) for fot[" << i0 << "].family_members[" << i1 << "].age" << endl;

        }


    }


    *GRADING << "Function fReturnAverageAgeOfFamilies invoked locally" << endl;
    float retVal = fReturnAverageAgeOfFamilies(fot);
    string retValStringRep = to_string(retVal);
    *GRADING << "Converting " << retVal << " of type float to string" << endl;

    RPCSTUBSOCKET->write(retValStringRep.c_str(), retValStringRep.length() + 1);
    *GRADING << "Sending value of retVal in string form - message: \"" << retVal << "\", length: " << retValStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function fReturnAverageAgeOfFamilies invocation done"<< endl;
}

void __fReturnAverageAgeOfFamily () { 
    char doneBuffer[5] = "DONE";
    FamilyOfThree fot;
    fot.lastname = getStringFromStream();
    *GRADING << "Received value for fot.lastname of type string - message: \"" << fot.lastname << "\", length: " << fot.lastname.length() + 1 << endl;

    
    for (int i0 = 0; i0 < 3; i0++) { 
        fot.family_members[i0].name = getStringFromStream();
        *GRADING << "Received value for fot.family_members[" << i0 << "].name of type string - message: \"" << fot.family_members[i0].name << "\", length: " << fot.family_members[i0].name.length() + 1 << endl;

        fot.family_members[i0].age = stoi(getStringFromStream());
        *GRADING << "Received value " << fot.family_members[i0].age << " (of type int in string form) for fot.family_members[" << i0 << "].age" << endl;

    }


    *GRADING << "Function fReturnAverageAgeOfFamily invoked locally" << endl;
    float retVal = fReturnAverageAgeOfFamily(fot);
    string retValStringRep = to_string(retVal);
    *GRADING << "Converting " << retVal << " of type float to string" << endl;

    RPCSTUBSOCKET->write(retValStringRep.c_str(), retValStringRep.length() + 1);
    *GRADING << "Sending value of retVal in string form - message: \"" << retVal << "\", length: " << retValStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function fReturnAverageAgeOfFamily invocation done"<< endl;
}

void __fReturnAverageAgeOfPeople () { 
    char doneBuffer[5] = "DONE";
    Person people[5][4];
    
    for (int i0 = 0; i0 < 5; i0++) { 
        
        for (int i1 = 0; i1 < 4; i1++) { 
            people[i0][i1].name = getStringFromStream();
            *GRADING << "Received value for people[" << i0 << "][" << i1 << "].name of type string - message: \"" << people[i0][i1].name << "\", length: " << people[i0][i1].name.length() + 1 << endl;

            people[i0][i1].age = stoi(getStringFromStream());
            *GRADING << "Received value " << people[i0][i1].age << " (of type int in string form) for people[" << i0 << "][" << i1 << "].age" << endl;

        }

    }


    *GRADING << "Function fReturnAverageAgeOfPeople invoked locally" << endl;
    float retVal = fReturnAverageAgeOfPeople(people);
    string retValStringRep = to_string(retVal);
    *GRADING << "Converting " << retVal << " of type float to string" << endl;

    RPCSTUBSOCKET->write(retValStringRep.c_str(), retValStringRep.length() + 1);
    *GRADING << "Sending value of retVal in string form - message: \"" << retVal << "\", length: " << retValStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function fReturnAverageAgeOfPeople invocation done"<< endl;
}

void __fReturnAverageAgeOfPersons () { 
    char doneBuffer[5] = "DONE";
    Person persons[5];
    
    for (int i0 = 0; i0 < 5; i0++) { 
        persons[i0].name = getStringFromStream();
        *GRADING << "Received value for persons[" << i0 << "].name of type string - message: \"" << persons[i0].name << "\", length: " << persons[i0].name.length() + 1 << endl;

        persons[i0].age = stoi(getStringFromStream());
        *GRADING << "Received value " << persons[i0].age << " (of type int in string form) for persons[" << i0 << "].age" << endl;

    }


    *GRADING << "Function fReturnAverageAgeOfPersons invoked locally" << endl;
    float retVal = fReturnAverageAgeOfPersons(persons);
    string retValStringRep = to_string(retVal);
    *GRADING << "Converting " << retVal << " of type float to string" << endl;

    RPCSTUBSOCKET->write(retValStringRep.c_str(), retValStringRep.length() + 1);
    *GRADING << "Sending value of retVal in string form - message: \"" << retVal << "\", length: " << retValStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function fReturnAverageAgeOfPersons invocation done"<< endl;
}

void __fReturnInputFloat () { 
    char doneBuffer[5] = "DONE";
    float input = stof(getStringFromStream());
    *GRADING << "Received value " << input << " (of type float in string form) for input" << endl;

    *GRADING << "Function fReturnInputFloat invoked locally" << endl;
    float retVal = fReturnInputFloat(input);
    string retValStringRep = to_string(retVal);
    *GRADING << "Converting " << retVal << " of type float to string" << endl;

    RPCSTUBSOCKET->write(retValStringRep.c_str(), retValStringRep.length() + 1);
    *GRADING << "Sending value of retVal in string form - message: \"" << retVal << "\", length: " << retValStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function fReturnInputFloat invocation done"<< endl;
}

void __fReturnInputInt () { 
    char doneBuffer[5] = "DONE";
    int input = stoi(getStringFromStream());
    *GRADING << "Received value " << input << " (of type int in string form) for input" << endl;

    *GRADING << "Function fReturnInputInt invoked locally" << endl;
    float retVal = fReturnInputInt(input);
    string retValStringRep = to_string(retVal);
    *GRADING << "Converting " << retVal << " of type float to string" << endl;

    RPCSTUBSOCKET->write(retValStringRep.c_str(), retValStringRep.length() + 1);
    *GRADING << "Sending value of retVal in string form - message: \"" << retVal << "\", length: " << retValStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function fReturnInputInt invocation done"<< endl;
}

void __fReturnInputString () { 
    char doneBuffer[5] = "DONE";
    string input = getStringFromStream();
    *GRADING << "Received value for input of type string - message: \"" << input << "\", length: " << input.length() + 1 << endl;

    *GRADING << "Function fReturnInputString invoked locally" << endl;
    float retVal = fReturnInputString(input);
    string retValStringRep = to_string(retVal);
    *GRADING << "Converting " << retVal << " of type float to string" << endl;

    RPCSTUBSOCKET->write(retValStringRep.c_str(), retValStringRep.length() + 1);
    *GRADING << "Sending value of retVal in string form - message: \"" << retVal << "\", length: " << retValStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function fReturnInputString invocation done"<< endl;
}

void __fReturnTwo () { 
    char doneBuffer[5] = "DONE";
    *GRADING << "Function fReturnTwo invoked locally" << endl;
    float retVal = fReturnTwo();
    string retValStringRep = to_string(retVal);
    *GRADING << "Converting " << retVal << " of type float to string" << endl;

    RPCSTUBSOCKET->write(retValStringRep.c_str(), retValStringRep.length() + 1);
    *GRADING << "Sending value of retVal in string form - message: \"" << retVal << "\", length: " << retValStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function fReturnTwo invocation done"<< endl;
}

void __makeCopyOfPerson () { 
    char doneBuffer[5] = "DONE";
    Person p;
    p.name = getStringFromStream();
    *GRADING << "Received value for p.name of type string - message: \"" << p.name << "\", length: " << p.name.length() + 1 << endl;

    p.age = stoi(getStringFromStream());
    *GRADING << "Received value " << p.age << " (of type int in string form) for p.age" << endl;

    *GRADING << "Function makeCopyOfPerson invoked locally" << endl;
    Person retVal = makeCopyOfPerson(p);
    RPCSTUBSOCKET->write(retVal.name.c_str(), retVal.name.length() + 1);
    *GRADING << "Sending value of retVal.name of type string - message: \"" << retVal.name << "\", length: " << retVal.name.length() + 1 << endl;

    string retValageStringRep = to_string(retVal.age);
    *GRADING << "Converting " << retVal.age << " of type int to string" << endl;

    RPCSTUBSOCKET->write(retValageStringRep.c_str(), retValageStringRep.length() + 1);
    *GRADING << "Sending value of retVal.age in string form - message: \"" << retVal.age << "\", length: " << retValageStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function makeCopyOfPerson invocation done"<< endl;
}

void __makeFamilyOfThree () { 
    char doneBuffer[5] = "DONE";
    *GRADING << "Function makeFamilyOfThree invoked locally" << endl;
    FamilyOfThree retVal = makeFamilyOfThree();
    RPCSTUBSOCKET->write(retVal.lastname.c_str(), retVal.lastname.length() + 1);
    *GRADING << "Sending value of retVal.lastname of type string - message: \"" << retVal.lastname << "\", length: " << retVal.lastname.length() + 1 << endl;

    
    for (int i0 = 0; i0 < 3; i0++) { 
        RPCSTUBSOCKET->write(retVal.family_members[i0].name.c_str(), retVal.family_members[i0].name.length() + 1);
        *GRADING << "Sending value of retVal.family_members[" << i0 << "].name of type string - message: \"" << retVal.family_members[i0].name << "\", length: " << retVal.family_members[i0].name.length() + 1 << endl;

        string retValfamily_membersi0ageStringRep = to_string(retVal.family_members[i0].age);
        *GRADING << "Converting " << retVal.family_members[i0].age << " of type int to string" << endl;

        RPCSTUBSOCKET->write(retValfamily_membersi0ageStringRep.c_str(), retValfamily_membersi0ageStringRep.length() + 1);
        *GRADING << "Sending value of retVal.family_members[" << i0 << "].age in string form - message: \"" << retVal.family_members[i0].age << "\", length: " << retValfamily_membersi0ageStringRep.length() + 1 << endl;

    }


    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function makeFamilyOfThree invocation done"<< endl;
}

void __makeFamilyWithAges () { 
    char doneBuffer[5] = "DONE";
    int age1 = stoi(getStringFromStream());
    *GRADING << "Received value " << age1 << " (of type int in string form) for age1" << endl;

    int age2 = stoi(getStringFromStream());
    *GRADING << "Received value " << age2 << " (of type int in string form) for age2" << endl;

    int age3 = stoi(getStringFromStream());
    *GRADING << "Received value " << age3 << " (of type int in string form) for age3" << endl;

    *GRADING << "Function makeFamilyWithAges invoked locally" << endl;
    FamilyOfThree retVal = makeFamilyWithAges(age1, age2, age3);
    RPCSTUBSOCKET->write(retVal.lastname.c_str(), retVal.lastname.length() + 1);
    *GRADING << "Sending value of retVal.lastname of type string - message: \"" << retVal.lastname << "\", length: " << retVal.lastname.length() + 1 << endl;

    
    for (int i0 = 0; i0 < 3; i0++) { 
        RPCSTUBSOCKET->write(retVal.family_members[i0].name.c_str(), retVal.family_members[i0].name.length() + 1);
        *GRADING << "Sending value of retVal.family_members[" << i0 << "].name of type string - message: \"" << retVal.family_members[i0].name << "\", length: " << retVal.family_members[i0].name.length() + 1 << endl;

        string retValfamily_membersi0ageStringRep = to_string(retVal.family_members[i0].age);
        *GRADING << "Converting " << retVal.family_members[i0].age << " of type int to string" << endl;

        RPCSTUBSOCKET->write(retValfamily_membersi0ageStringRep.c_str(), retValfamily_membersi0ageStringRep.length() + 1);
        *GRADING << "Sending value of retVal.family_members[" << i0 << "].age in string form - message: \"" << retVal.family_members[i0].age << "\", length: " << retValfamily_membersi0ageStringRep.length() + 1 << endl;

    }


    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function makeFamilyWithAges invocation done"<< endl;
}

void __makeFamilyWithName () { 
    char doneBuffer[5] = "DONE";
    string lastname = getStringFromStream();
    *GRADING << "Received value for lastname of type string - message: \"" << lastname << "\", length: " << lastname.length() + 1 << endl;

    *GRADING << "Function makeFamilyWithName invoked locally" << endl;
    FamilyOfThree retVal = makeFamilyWithName(lastname);
    RPCSTUBSOCKET->write(retVal.lastname.c_str(), retVal.lastname.length() + 1);
    *GRADING << "Sending value of retVal.lastname of type string - message: \"" << retVal.lastname << "\", length: " << retVal.lastname.length() + 1 << endl;

    
    for (int i0 = 0; i0 < 3; i0++) { 
        RPCSTUBSOCKET->write(retVal.family_members[i0].name.c_str(), retVal.family_members[i0].name.length() + 1);
        *GRADING << "Sending value of retVal.family_members[" << i0 << "].name of type string - message: \"" << retVal.family_members[i0].name << "\", length: " << retVal.family_members[i0].name.length() + 1 << endl;

        string retValfamily_membersi0ageStringRep = to_string(retVal.family_members[i0].age);
        *GRADING << "Converting " << retVal.family_members[i0].age << " of type int to string" << endl;

        RPCSTUBSOCKET->write(retValfamily_membersi0ageStringRep.c_str(), retValfamily_membersi0ageStringRep.length() + 1);
        *GRADING << "Sending value of retVal.family_members[" << i0 << "].age in string form - message: \"" << retVal.family_members[i0].age << "\", length: " << retValfamily_membersi0ageStringRep.length() + 1 << endl;

    }


    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function makeFamilyWithName invocation done"<< endl;
}

void __makeFamilyWithPersonArray () { 
    char doneBuffer[5] = "DONE";
    Person fofthree[3];
    
    for (int i0 = 0; i0 < 3; i0++) { 
        fofthree[i0].name = getStringFromStream();
        *GRADING << "Received value for fofthree[" << i0 << "].name of type string - message: \"" << fofthree[i0].name << "\", length: " << fofthree[i0].name.length() + 1 << endl;

        fofthree[i0].age = stoi(getStringFromStream());
        *GRADING << "Received value " << fofthree[i0].age << " (of type int in string form) for fofthree[" << i0 << "].age" << endl;

    }


    *GRADING << "Function makeFamilyWithPersonArray invoked locally" << endl;
    FamilyOfThree retVal = makeFamilyWithPersonArray(fofthree);
    RPCSTUBSOCKET->write(retVal.lastname.c_str(), retVal.lastname.length() + 1);
    *GRADING << "Sending value of retVal.lastname of type string - message: \"" << retVal.lastname << "\", length: " << retVal.lastname.length() + 1 << endl;

    
    for (int i0 = 0; i0 < 3; i0++) { 
        RPCSTUBSOCKET->write(retVal.family_members[i0].name.c_str(), retVal.family_members[i0].name.length() + 1);
        *GRADING << "Sending value of retVal.family_members[" << i0 << "].name of type string - message: \"" << retVal.family_members[i0].name << "\", length: " << retVal.family_members[i0].name.length() + 1 << endl;

        string retValfamily_membersi0ageStringRep = to_string(retVal.family_members[i0].age);
        *GRADING << "Converting " << retVal.family_members[i0].age << " of type int to string" << endl;

        RPCSTUBSOCKET->write(retValfamily_membersi0ageStringRep.c_str(), retValfamily_membersi0ageStringRep.length() + 1);
        *GRADING << "Sending value of retVal.family_members[" << i0 << "].age in string form - message: \"" << retVal.family_members[i0].age << "\", length: " << retValfamily_membersi0ageStringRep.length() + 1 << endl;

    }


    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function makeFamilyWithPersonArray invocation done"<< endl;
}

void __makeFamilyWithPersons () { 
    char doneBuffer[5] = "DONE";
    Person p1;
    p1.name = getStringFromStream();
    *GRADING << "Received value for p1.name of type string - message: \"" << p1.name << "\", length: " << p1.name.length() + 1 << endl;

    p1.age = stoi(getStringFromStream());
    *GRADING << "Received value " << p1.age << " (of type int in string form) for p1.age" << endl;

    Person p2;
    p2.name = getStringFromStream();
    *GRADING << "Received value for p2.name of type string - message: \"" << p2.name << "\", length: " << p2.name.length() + 1 << endl;

    p2.age = stoi(getStringFromStream());
    *GRADING << "Received value " << p2.age << " (of type int in string form) for p2.age" << endl;

    Person p3;
    p3.name = getStringFromStream();
    *GRADING << "Received value for p3.name of type string - message: \"" << p3.name << "\", length: " << p3.name.length() + 1 << endl;

    p3.age = stoi(getStringFromStream());
    *GRADING << "Received value " << p3.age << " (of type int in string form) for p3.age" << endl;

    *GRADING << "Function makeFamilyWithPersons invoked locally" << endl;
    FamilyOfThree retVal = makeFamilyWithPersons(p1, p2, p3);
    RPCSTUBSOCKET->write(retVal.lastname.c_str(), retVal.lastname.length() + 1);
    *GRADING << "Sending value of retVal.lastname of type string - message: \"" << retVal.lastname << "\", length: " << retVal.lastname.length() + 1 << endl;

    
    for (int i0 = 0; i0 < 3; i0++) { 
        RPCSTUBSOCKET->write(retVal.family_members[i0].name.c_str(), retVal.family_members[i0].name.length() + 1);
        *GRADING << "Sending value of retVal.family_members[" << i0 << "].name of type string - message: \"" << retVal.family_members[i0].name << "\", length: " << retVal.family_members[i0].name.length() + 1 << endl;

        string retValfamily_membersi0ageStringRep = to_string(retVal.family_members[i0].age);
        *GRADING << "Converting " << retVal.family_members[i0].age << " of type int to string" << endl;

        RPCSTUBSOCKET->write(retValfamily_membersi0ageStringRep.c_str(), retValfamily_membersi0ageStringRep.length() + 1);
        *GRADING << "Sending value of retVal.family_members[" << i0 << "].age in string form - message: \"" << retVal.family_members[i0].age << "\", length: " << retValfamily_membersi0ageStringRep.length() + 1 << endl;

    }


    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function makeFamilyWithPersons invocation done"<< endl;
}

void __makePersonAgeAndAHalfYearsOld () { 
    char doneBuffer[5] = "DONE";
    float age = stof(getStringFromStream());
    *GRADING << "Received value " << age << " (of type float in string form) for age" << endl;

    *GRADING << "Function makePersonAgeAndAHalfYearsOld invoked locally" << endl;
    Person retVal = makePersonAgeAndAHalfYearsOld(age);
    RPCSTUBSOCKET->write(retVal.name.c_str(), retVal.name.length() + 1);
    *GRADING << "Sending value of retVal.name of type string - message: \"" << retVal.name << "\", length: " << retVal.name.length() + 1 << endl;

    string retValageStringRep = to_string(retVal.age);
    *GRADING << "Converting " << retVal.age << " of type int to string" << endl;

    RPCSTUBSOCKET->write(retValageStringRep.c_str(), retValageStringRep.length() + 1);
    *GRADING << "Sending value of retVal.age in string form - message: \"" << retVal.age << "\", length: " << retValageStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function makePersonAgeAndAHalfYearsOld invocation done"<< endl;
}

void __makePersonAgeYearsOld () { 
    char doneBuffer[5] = "DONE";
    int age = stoi(getStringFromStream());
    *GRADING << "Received value " << age << " (of type int in string form) for age" << endl;

    *GRADING << "Function makePersonAgeYearsOld invoked locally" << endl;
    Person retVal = makePersonAgeYearsOld(age);
    RPCSTUBSOCKET->write(retVal.name.c_str(), retVal.name.length() + 1);
    *GRADING << "Sending value of retVal.name of type string - message: \"" << retVal.name << "\", length: " << retVal.name.length() + 1 << endl;

    string retValageStringRep = to_string(retVal.age);
    *GRADING << "Converting " << retVal.age << " of type int to string" << endl;

    RPCSTUBSOCKET->write(retValageStringRep.c_str(), retValageStringRep.length() + 1);
    *GRADING << "Sending value of retVal.age in string form - message: \"" << retVal.age << "\", length: " << retValageStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function makePersonAgeYearsOld invocation done"<< endl;
}

void __makePersonWithName () { 
    char doneBuffer[5] = "DONE";
    string name = getStringFromStream();
    *GRADING << "Received value for name of type string - message: \"" << name << "\", length: " << name.length() + 1 << endl;

    *GRADING << "Function makePersonWithName invoked locally" << endl;
    Person retVal = makePersonWithName(name);
    RPCSTUBSOCKET->write(retVal.name.c_str(), retVal.name.length() + 1);
    *GRADING << "Sending value of retVal.name of type string - message: \"" << retVal.name << "\", length: " << retVal.name.length() + 1 << endl;

    string retValageStringRep = to_string(retVal.age);
    *GRADING << "Converting " << retVal.age << " of type int to string" << endl;

    RPCSTUBSOCKET->write(retValageStringRep.c_str(), retValageStringRep.length() + 1);
    *GRADING << "Sending value of retVal.age in string form - message: \"" << retVal.age << "\", length: " << retValageStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function makePersonWithName invocation done"<< endl;
}

void __makeRandomPerson () { 
    char doneBuffer[5] = "DONE";
    *GRADING << "Function makeRandomPerson invoked locally" << endl;
    Person retVal = makeRandomPerson();
    RPCSTUBSOCKET->write(retVal.name.c_str(), retVal.name.length() + 1);
    *GRADING << "Sending value of retVal.name of type string - message: \"" << retVal.name << "\", length: " << retVal.name.length() + 1 << endl;

    string retValageStringRep = to_string(retVal.age);
    *GRADING << "Converting " << retVal.age << " of type int to string" << endl;

    RPCSTUBSOCKET->write(retValageStringRep.c_str(), retValageStringRep.length() + 1);
    *GRADING << "Sending value of retVal.age in string form - message: \"" << retVal.age << "\", length: " << retValageStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function makeRandomPerson invocation done"<< endl;
}

void __printFamilies () { 
    char doneBuffer[5] = "DONE";
    FamilyOfThree fot[5];
    
    for (int i0 = 0; i0 < 5; i0++) { 
        fot[i0].lastname = getStringFromStream();
        *GRADING << "Received value for fot[" << i0 << "].lastname of type string - message: \"" << fot[i0].lastname << "\", length: " << fot[i0].lastname.length() + 1 << endl;

        
        for (int i1 = 0; i1 < 3; i1++) { 
            fot[i0].family_members[i1].name = getStringFromStream();
            *GRADING << "Received value for fot[" << i0 << "].family_members[" << i1 << "].name of type string - message: \"" << fot[i0].family_members[i1].name << "\", length: " << fot[i0].family_members[i1].name.length() + 1 << endl;

            fot[i0].family_members[i1].age = stoi(getStringFromStream());
            *GRADING << "Received value " << fot[i0].family_members[i1].age << " (of type int in string form) for fot[" << i0 << "].family_members[" << i1 << "].age" << endl;

        }


    }


    *GRADING << "Function printFamilies invoked locally" << endl;
    printFamilies(fot);
    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function printFamilies invocation done"<< endl;
}

void __printFamily () { 
    char doneBuffer[5] = "DONE";
    FamilyOfThree fot;
    fot.lastname = getStringFromStream();
    *GRADING << "Received value for fot.lastname of type string - message: \"" << fot.lastname << "\", length: " << fot.lastname.length() + 1 << endl;

    
    for (int i0 = 0; i0 < 3; i0++) { 
        fot.family_members[i0].name = getStringFromStream();
        *GRADING << "Received value for fot.family_members[" << i0 << "].name of type string - message: \"" << fot.family_members[i0].name << "\", length: " << fot.family_members[i0].name.length() + 1 << endl;

        fot.family_members[i0].age = stoi(getStringFromStream());
        *GRADING << "Received value " << fot.family_members[i0].age << " (of type int in string form) for fot.family_members[" << i0 << "].age" << endl;

    }


    *GRADING << "Function printFamily invoked locally" << endl;
    printFamily(fot);
    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function printFamily invocation done"<< endl;
}

void __printNone () { 
    char doneBuffer[5] = "DONE";
    *GRADING << "Function printNone invoked locally" << endl;
    printNone();
    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function printNone invocation done"<< endl;
}

void __printOne () { 
    char doneBuffer[5] = "DONE";
    int one = stoi(getStringFromStream());
    *GRADING << "Received value " << one << " (of type int in string form) for one" << endl;

    *GRADING << "Function printOne invoked locally" << endl;
    printOne(one);
    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function printOne invocation done"<< endl;
}

void __printPerson () { 
    char doneBuffer[5] = "DONE";
    Person idil;
    idil.name = getStringFromStream();
    *GRADING << "Received value for idil.name of type string - message: \"" << idil.name << "\", length: " << idil.name.length() + 1 << endl;

    idil.age = stoi(getStringFromStream());
    *GRADING << "Received value " << idil.age << " (of type int in string form) for idil.age" << endl;

    *GRADING << "Function printPerson invoked locally" << endl;
    printPerson(idil);
    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function printPerson invocation done"<< endl;
}

void __printPersons () { 
    char doneBuffer[5] = "DONE";
    Person persons[5];
    
    for (int i0 = 0; i0 < 5; i0++) { 
        persons[i0].name = getStringFromStream();
        *GRADING << "Received value for persons[" << i0 << "].name of type string - message: \"" << persons[i0].name << "\", length: " << persons[i0].name.length() + 1 << endl;

        persons[i0].age = stoi(getStringFromStream());
        *GRADING << "Received value " << persons[i0].age << " (of type int in string form) for persons[" << i0 << "].age" << endl;

    }


    *GRADING << "Function printPersons invoked locally" << endl;
    printPersons(persons);
    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function printPersons invocation done"<< endl;
}

void __printPersonsOfPersons () { 
    char doneBuffer[5] = "DONE";
    Person people[5][4];
    
    for (int i0 = 0; i0 < 5; i0++) { 
        
        for (int i1 = 0; i1 < 4; i1++) { 
            people[i0][i1].name = getStringFromStream();
            *GRADING << "Received value for people[" << i0 << "][" << i1 << "].name of type string - message: \"" << people[i0][i1].name << "\", length: " << people[i0][i1].name.length() + 1 << endl;

            people[i0][i1].age = stoi(getStringFromStream());
            *GRADING << "Received value " << people[i0][i1].age << " (of type int in string form) for people[" << i0 << "][" << i1 << "].age" << endl;

        }

    }


    *GRADING << "Function printPersonsOfPersons invoked locally" << endl;
    printPersonsOfPersons(people);
    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function printPersonsOfPersons invocation done"<< endl;
}

void __printRelative () { 
    char doneBuffer[5] = "DONE";
    Relative idils_sister;
    idils_sister.name = getStringFromStream();
    *GRADING << "Received value for idils_sister.name of type string - message: \"" << idils_sister.name << "\", length: " << idils_sister.name.length() + 1 << endl;

    idils_sister.age = stoi(getStringFromStream());
    *GRADING << "Received value " << idils_sister.age << " (of type int in string form) for idils_sister.age" << endl;

    idils_sister.r.name = getStringFromStream();
    *GRADING << "Received value for idils_sister.r.name of type string - message: \"" << idils_sister.r.name << "\", length: " << idils_sister.r.name.length() + 1 << endl;

    idils_sister.r.age = stoi(getStringFromStream());
    *GRADING << "Received value " << idils_sister.r.age << " (of type int in string form) for idils_sister.r.age" << endl;

    *GRADING << "Function printRelative invoked locally" << endl;
    printRelative(idils_sister);
    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function printRelative invocation done"<< endl;
}

void __printThis () { 
    char doneBuffer[5] = "DONE";
    string thisword = getStringFromStream();
    *GRADING << "Received value for thisword of type string - message: \"" << thisword << "\", length: " << thisword.length() + 1 << endl;

    *GRADING << "Function printThis invoked locally" << endl;
    printThis(thisword);
    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function printThis invocation done"<< endl;
}

void __printTwo () { 
    char doneBuffer[5] = "DONE";
    float two = stof(getStringFromStream());
    *GRADING << "Received value " << two << " (of type float in string form) for two" << endl;

    *GRADING << "Function printTwo invoked locally" << endl;
    printTwo(two);
    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function printTwo invocation done"<< endl;
}

void __returnAgeOfPerson () { 
    char doneBuffer[5] = "DONE";
    Person idil;
    idil.name = getStringFromStream();
    *GRADING << "Received value for idil.name of type string - message: \"" << idil.name << "\", length: " << idil.name.length() + 1 << endl;

    idil.age = stoi(getStringFromStream());
    *GRADING << "Received value " << idil.age << " (of type int in string form) for idil.age" << endl;

    *GRADING << "Function returnAgeOfPerson invoked locally" << endl;
    int retVal = returnAgeOfPerson(idil);
    string retValStringRep = to_string(retVal);
    *GRADING << "Converting " << retVal << " of type int to string" << endl;

    RPCSTUBSOCKET->write(retValStringRep.c_str(), retValStringRep.length() + 1);
    *GRADING << "Sending value of retVal in string form - message: \"" << retVal << "\", length: " << retValStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function returnAgeOfPerson invocation done"<< endl;
}

void __returnAgeOfRelativeOfPerson () { 
    char doneBuffer[5] = "DONE";
    Relative idils_sister;
    idils_sister.name = getStringFromStream();
    *GRADING << "Received value for idils_sister.name of type string - message: \"" << idils_sister.name << "\", length: " << idils_sister.name.length() + 1 << endl;

    idils_sister.age = stoi(getStringFromStream());
    *GRADING << "Received value " << idils_sister.age << " (of type int in string form) for idils_sister.age" << endl;

    idils_sister.r.name = getStringFromStream();
    *GRADING << "Received value for idils_sister.r.name of type string - message: \"" << idils_sister.r.name << "\", length: " << idils_sister.r.name.length() + 1 << endl;

    idils_sister.r.age = stoi(getStringFromStream());
    *GRADING << "Received value " << idils_sister.r.age << " (of type int in string form) for idils_sister.r.age" << endl;

    *GRADING << "Function returnAgeOfRelativeOfPerson invoked locally" << endl;
    int retVal = returnAgeOfRelativeOfPerson(idils_sister);
    string retValStringRep = to_string(retVal);
    *GRADING << "Converting " << retVal << " of type int to string" << endl;

    RPCSTUBSOCKET->write(retValStringRep.c_str(), retValStringRep.length() + 1);
    *GRADING << "Sending value of retVal in string form - message: \"" << retVal << "\", length: " << retValStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function returnAgeOfRelativeOfPerson invocation done"<< endl;
}

void __returnAverageAgeOfFamilies () { 
    char doneBuffer[5] = "DONE";
    FamilyOfThree fot[5];
    
    for (int i0 = 0; i0 < 5; i0++) { 
        fot[i0].lastname = getStringFromStream();
        *GRADING << "Received value for fot[" << i0 << "].lastname of type string - message: \"" << fot[i0].lastname << "\", length: " << fot[i0].lastname.length() + 1 << endl;

        
        for (int i1 = 0; i1 < 3; i1++) { 
            fot[i0].family_members[i1].name = getStringFromStream();
            *GRADING << "Received value for fot[" << i0 << "].family_members[" << i1 << "].name of type string - message: \"" << fot[i0].family_members[i1].name << "\", length: " << fot[i0].family_members[i1].name.length() + 1 << endl;

            fot[i0].family_members[i1].age = stoi(getStringFromStream());
            *GRADING << "Received value " << fot[i0].family_members[i1].age << " (of type int in string form) for fot[" << i0 << "].family_members[" << i1 << "].age" << endl;

        }


    }


    *GRADING << "Function returnAverageAgeOfFamilies invoked locally" << endl;
    int retVal = returnAverageAgeOfFamilies(fot);
    string retValStringRep = to_string(retVal);
    *GRADING << "Converting " << retVal << " of type int to string" << endl;

    RPCSTUBSOCKET->write(retValStringRep.c_str(), retValStringRep.length() + 1);
    *GRADING << "Sending value of retVal in string form - message: \"" << retVal << "\", length: " << retValStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function returnAverageAgeOfFamilies invocation done"<< endl;
}

void __returnAverageAgeOfFamily () { 
    char doneBuffer[5] = "DONE";
    FamilyOfThree fot;
    fot.lastname = getStringFromStream();
    *GRADING << "Received value for fot.lastname of type string - message: \"" << fot.lastname << "\", length: " << fot.lastname.length() + 1 << endl;

    
    for (int i0 = 0; i0 < 3; i0++) { 
        fot.family_members[i0].name = getStringFromStream();
        *GRADING << "Received value for fot.family_members[" << i0 << "].name of type string - message: \"" << fot.family_members[i0].name << "\", length: " << fot.family_members[i0].name.length() + 1 << endl;

        fot.family_members[i0].age = stoi(getStringFromStream());
        *GRADING << "Received value " << fot.family_members[i0].age << " (of type int in string form) for fot.family_members[" << i0 << "].age" << endl;

    }


    *GRADING << "Function returnAverageAgeOfFamily invoked locally" << endl;
    int retVal = returnAverageAgeOfFamily(fot);
    string retValStringRep = to_string(retVal);
    *GRADING << "Converting " << retVal << " of type int to string" << endl;

    RPCSTUBSOCKET->write(retValStringRep.c_str(), retValStringRep.length() + 1);
    *GRADING << "Sending value of retVal in string form - message: \"" << retVal << "\", length: " << retValStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function returnAverageAgeOfFamily invocation done"<< endl;
}

void __returnAverageAgeOfPeople () { 
    char doneBuffer[5] = "DONE";
    Person people[5][4];
    
    for (int i0 = 0; i0 < 5; i0++) { 
        
        for (int i1 = 0; i1 < 4; i1++) { 
            people[i0][i1].name = getStringFromStream();
            *GRADING << "Received value for people[" << i0 << "][" << i1 << "].name of type string - message: \"" << people[i0][i1].name << "\", length: " << people[i0][i1].name.length() + 1 << endl;

            people[i0][i1].age = stoi(getStringFromStream());
            *GRADING << "Received value " << people[i0][i1].age << " (of type int in string form) for people[" << i0 << "][" << i1 << "].age" << endl;

        }

    }


    *GRADING << "Function returnAverageAgeOfPeople invoked locally" << endl;
    int retVal = returnAverageAgeOfPeople(people);
    string retValStringRep = to_string(retVal);
    *GRADING << "Converting " << retVal << " of type int to string" << endl;

    RPCSTUBSOCKET->write(retValStringRep.c_str(), retValStringRep.length() + 1);
    *GRADING << "Sending value of retVal in string form - message: \"" << retVal << "\", length: " << retValStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function returnAverageAgeOfPeople invocation done"<< endl;
}

void __returnAverageAgeOfPersons () { 
    char doneBuffer[5] = "DONE";
    Person persons[5];
    
    for (int i0 = 0; i0 < 5; i0++) { 
        persons[i0].name = getStringFromStream();
        *GRADING << "Received value for persons[" << i0 << "].name of type string - message: \"" << persons[i0].name << "\", length: " << persons[i0].name.length() + 1 << endl;

        persons[i0].age = stoi(getStringFromStream());
        *GRADING << "Received value " << persons[i0].age << " (of type int in string form) for persons[" << i0 << "].age" << endl;

    }


    *GRADING << "Function returnAverageAgeOfPersons invoked locally" << endl;
    int retVal = returnAverageAgeOfPersons(persons);
    string retValStringRep = to_string(retVal);
    *GRADING << "Converting " << retVal << " of type int to string" << endl;

    RPCSTUBSOCKET->write(retValStringRep.c_str(), retValStringRep.length() + 1);
    *GRADING << "Sending value of retVal in string form - message: \"" << retVal << "\", length: " << retValStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function returnAverageAgeOfPersons invocation done"<< endl;
}

void __returnInputFloat () { 
    char doneBuffer[5] = "DONE";
    float input = stof(getStringFromStream());
    *GRADING << "Received value " << input << " (of type float in string form) for input" << endl;

    *GRADING << "Function returnInputFloat invoked locally" << endl;
    int retVal = returnInputFloat(input);
    string retValStringRep = to_string(retVal);
    *GRADING << "Converting " << retVal << " of type int to string" << endl;

    RPCSTUBSOCKET->write(retValStringRep.c_str(), retValStringRep.length() + 1);
    *GRADING << "Sending value of retVal in string form - message: \"" << retVal << "\", length: " << retValStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function returnInputFloat invocation done"<< endl;
}

void __returnInputInt () { 
    char doneBuffer[5] = "DONE";
    int input = stoi(getStringFromStream());
    *GRADING << "Received value " << input << " (of type int in string form) for input" << endl;

    *GRADING << "Function returnInputInt invoked locally" << endl;
    int retVal = returnInputInt(input);
    string retValStringRep = to_string(retVal);
    *GRADING << "Converting " << retVal << " of type int to string" << endl;

    RPCSTUBSOCKET->write(retValStringRep.c_str(), retValStringRep.length() + 1);
    *GRADING << "Sending value of retVal in string form - message: \"" << retVal << "\", length: " << retValStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function returnInputInt invocation done"<< endl;
}

void __returnInputString () { 
    char doneBuffer[5] = "DONE";
    string input = getStringFromStream();
    *GRADING << "Received value for input of type string - message: \"" << input << "\", length: " << input.length() + 1 << endl;

    *GRADING << "Function returnInputString invoked locally" << endl;
    int retVal = returnInputString(input);
    string retValStringRep = to_string(retVal);
    *GRADING << "Converting " << retVal << " of type int to string" << endl;

    RPCSTUBSOCKET->write(retValStringRep.c_str(), retValStringRep.length() + 1);
    *GRADING << "Sending value of retVal in string form - message: \"" << retVal << "\", length: " << retValStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function returnInputString invocation done"<< endl;
}

void __returnOldestAverageFamily () { 
    char doneBuffer[5] = "DONE";
    FamilyOfThree fot[5];
    
    for (int i0 = 0; i0 < 5; i0++) { 
        fot[i0].lastname = getStringFromStream();
        *GRADING << "Received value for fot[" << i0 << "].lastname of type string - message: \"" << fot[i0].lastname << "\", length: " << fot[i0].lastname.length() + 1 << endl;

        
        for (int i1 = 0; i1 < 3; i1++) { 
            fot[i0].family_members[i1].name = getStringFromStream();
            *GRADING << "Received value for fot[" << i0 << "].family_members[" << i1 << "].name of type string - message: \"" << fot[i0].family_members[i1].name << "\", length: " << fot[i0].family_members[i1].name.length() + 1 << endl;

            fot[i0].family_members[i1].age = stoi(getStringFromStream());
            *GRADING << "Received value " << fot[i0].family_members[i1].age << " (of type int in string form) for fot[" << i0 << "].family_members[" << i1 << "].age" << endl;

        }


    }


    *GRADING << "Function returnOldestAverageFamily invoked locally" << endl;
    Person retVal = returnOldestAverageFamily(fot);
    RPCSTUBSOCKET->write(retVal.name.c_str(), retVal.name.length() + 1);
    *GRADING << "Sending value of retVal.name of type string - message: \"" << retVal.name << "\", length: " << retVal.name.length() + 1 << endl;

    string retValageStringRep = to_string(retVal.age);
    *GRADING << "Converting " << retVal.age << " of type int to string" << endl;

    RPCSTUBSOCKET->write(retValageStringRep.c_str(), retValageStringRep.length() + 1);
    *GRADING << "Sending value of retVal.age in string form - message: \"" << retVal.age << "\", length: " << retValageStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function returnOldestAverageFamily invocation done"<< endl;
}

void __returnOldestFamily () { 
    char doneBuffer[5] = "DONE";
    FamilyOfThree families[5];
    
    for (int i0 = 0; i0 < 5; i0++) { 
        families[i0].lastname = getStringFromStream();
        *GRADING << "Received value for families[" << i0 << "].lastname of type string - message: \"" << families[i0].lastname << "\", length: " << families[i0].lastname.length() + 1 << endl;

        
        for (int i1 = 0; i1 < 3; i1++) { 
            families[i0].family_members[i1].name = getStringFromStream();
            *GRADING << "Received value for families[" << i0 << "].family_members[" << i1 << "].name of type string - message: \"" << families[i0].family_members[i1].name << "\", length: " << families[i0].family_members[i1].name.length() + 1 << endl;

            families[i0].family_members[i1].age = stoi(getStringFromStream());
            *GRADING << "Received value " << families[i0].family_members[i1].age << " (of type int in string form) for families[" << i0 << "].family_members[" << i1 << "].age" << endl;

        }


    }


    *GRADING << "Function returnOldestFamily invoked locally" << endl;
    FamilyOfThree retVal = returnOldestFamily(families);
    RPCSTUBSOCKET->write(retVal.lastname.c_str(), retVal.lastname.length() + 1);
    *GRADING << "Sending value of retVal.lastname of type string - message: \"" << retVal.lastname << "\", length: " << retVal.lastname.length() + 1 << endl;

    
    for (int i0 = 0; i0 < 3; i0++) { 
        RPCSTUBSOCKET->write(retVal.family_members[i0].name.c_str(), retVal.family_members[i0].name.length() + 1);
        *GRADING << "Sending value of retVal.family_members[" << i0 << "].name of type string - message: \"" << retVal.family_members[i0].name << "\", length: " << retVal.family_members[i0].name.length() + 1 << endl;

        string retValfamily_membersi0ageStringRep = to_string(retVal.family_members[i0].age);
        *GRADING << "Converting " << retVal.family_members[i0].age << " of type int to string" << endl;

        RPCSTUBSOCKET->write(retValfamily_membersi0ageStringRep.c_str(), retValfamily_membersi0ageStringRep.length() + 1);
        *GRADING << "Sending value of retVal.family_members[" << i0 << "].age in string form - message: \"" << retVal.family_members[i0].age << "\", length: " << retValfamily_membersi0ageStringRep.length() + 1 << endl;

    }


    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function returnOldestFamily invocation done"<< endl;
}

void __returnOldestMember () { 
    char doneBuffer[5] = "DONE";
    FamilyOfThree fot;
    fot.lastname = getStringFromStream();
    *GRADING << "Received value for fot.lastname of type string - message: \"" << fot.lastname << "\", length: " << fot.lastname.length() + 1 << endl;

    
    for (int i0 = 0; i0 < 3; i0++) { 
        fot.family_members[i0].name = getStringFromStream();
        *GRADING << "Received value for fot.family_members[" << i0 << "].name of type string - message: \"" << fot.family_members[i0].name << "\", length: " << fot.family_members[i0].name.length() + 1 << endl;

        fot.family_members[i0].age = stoi(getStringFromStream());
        *GRADING << "Received value " << fot.family_members[i0].age << " (of type int in string form) for fot.family_members[" << i0 << "].age" << endl;

    }


    *GRADING << "Function returnOldestMember invoked locally" << endl;
    Person retVal = returnOldestMember(fot);
    RPCSTUBSOCKET->write(retVal.name.c_str(), retVal.name.length() + 1);
    *GRADING << "Sending value of retVal.name of type string - message: \"" << retVal.name << "\", length: " << retVal.name.length() + 1 << endl;

    string retValageStringRep = to_string(retVal.age);
    *GRADING << "Converting " << retVal.age << " of type int to string" << endl;

    RPCSTUBSOCKET->write(retValageStringRep.c_str(), retValageStringRep.length() + 1);
    *GRADING << "Sending value of retVal.age in string form - message: \"" << retVal.age << "\", length: " << retValageStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function returnOldestMember invocation done"<< endl;
}

void __returnRelativeAYearOlder () { 
    char doneBuffer[5] = "DONE";
    Relative idils_sister;
    idils_sister.name = getStringFromStream();
    *GRADING << "Received value for idils_sister.name of type string - message: \"" << idils_sister.name << "\", length: " << idils_sister.name.length() + 1 << endl;

    idils_sister.age = stoi(getStringFromStream());
    *GRADING << "Received value " << idils_sister.age << " (of type int in string form) for idils_sister.age" << endl;

    idils_sister.r.name = getStringFromStream();
    *GRADING << "Received value for idils_sister.r.name of type string - message: \"" << idils_sister.r.name << "\", length: " << idils_sister.r.name.length() + 1 << endl;

    idils_sister.r.age = stoi(getStringFromStream());
    *GRADING << "Received value " << idils_sister.r.age << " (of type int in string form) for idils_sister.r.age" << endl;

    *GRADING << "Function returnRelativeAYearOlder invoked locally" << endl;
    Person retVal = returnRelativeAYearOlder(idils_sister);
    RPCSTUBSOCKET->write(retVal.name.c_str(), retVal.name.length() + 1);
    *GRADING << "Sending value of retVal.name of type string - message: \"" << retVal.name << "\", length: " << retVal.name.length() + 1 << endl;

    string retValageStringRep = to_string(retVal.age);
    *GRADING << "Converting " << retVal.age << " of type int to string" << endl;

    RPCSTUBSOCKET->write(retValageStringRep.c_str(), retValageStringRep.length() + 1);
    *GRADING << "Sending value of retVal.age in string form - message: \"" << retVal.age << "\", length: " << retValageStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function returnRelativeAYearOlder invocation done"<< endl;
}

void __returnTwo () { 
    char doneBuffer[5] = "DONE";
    *GRADING << "Function returnTwo invoked locally" << endl;
    int retVal = returnTwo();
    string retValStringRep = to_string(retVal);
    *GRADING << "Converting " << retVal << " of type int to string" << endl;

    RPCSTUBSOCKET->write(retValStringRep.c_str(), retValStringRep.length() + 1);
    *GRADING << "Sending value of retVal in string form - message: \"" << retVal << "\", length: " << retValStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function returnTwo invocation done"<< endl;
}

void __returnYoungestAveragePeople () { 
    char doneBuffer[5] = "DONE";
    Person people[5][4];
    
    for (int i0 = 0; i0 < 5; i0++) { 
        
        for (int i1 = 0; i1 < 4; i1++) { 
            people[i0][i1].name = getStringFromStream();
            *GRADING << "Received value for people[" << i0 << "][" << i1 << "].name of type string - message: \"" << people[i0][i1].name << "\", length: " << people[i0][i1].name.length() + 1 << endl;

            people[i0][i1].age = stoi(getStringFromStream());
            *GRADING << "Received value " << people[i0][i1].age << " (of type int in string form) for people[" << i0 << "][" << i1 << "].age" << endl;

        }

    }


    *GRADING << "Function returnYoungestAveragePeople invoked locally" << endl;
    Person retVal = returnYoungestAveragePeople(people);
    RPCSTUBSOCKET->write(retVal.name.c_str(), retVal.name.length() + 1);
    *GRADING << "Sending value of retVal.name of type string - message: \"" << retVal.name << "\", length: " << retVal.name.length() + 1 << endl;

    string retValageStringRep = to_string(retVal.age);
    *GRADING << "Converting " << retVal.age << " of type int to string" << endl;

    RPCSTUBSOCKET->write(retValageStringRep.c_str(), retValageStringRep.length() + 1);
    *GRADING << "Sending value of retVal.age in string form - message: \"" << retVal.age << "\", length: " << retValageStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function returnYoungestAveragePeople invocation done"<< endl;
}

void __returnYoungestMember () { 
    char doneBuffer[5] = "DONE";
    Person persons[5];
    
    for (int i0 = 0; i0 < 5; i0++) { 
        persons[i0].name = getStringFromStream();
        *GRADING << "Received value for persons[" << i0 << "].name of type string - message: \"" << persons[i0].name << "\", length: " << persons[i0].name.length() + 1 << endl;

        persons[i0].age = stoi(getStringFromStream());
        *GRADING << "Received value " << persons[i0].age << " (of type int in string form) for persons[" << i0 << "].age" << endl;

    }


    *GRADING << "Function returnYoungestMember invoked locally" << endl;
    Person retVal = returnYoungestMember(persons);
    RPCSTUBSOCKET->write(retVal.name.c_str(), retVal.name.length() + 1);
    *GRADING << "Sending value of retVal.name of type string - message: \"" << retVal.name << "\", length: " << retVal.name.length() + 1 << endl;

    string retValageStringRep = to_string(retVal.age);
    *GRADING << "Converting " << retVal.age << " of type int to string" << endl;

    RPCSTUBSOCKET->write(retValageStringRep.c_str(), retValageStringRep.length() + 1);
    *GRADING << "Sending value of retVal.age in string form - message: \"" << retVal.age << "\", length: " << retValageStringRep.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function returnYoungestMember invocation done"<< endl;
}

void __sReturnAgeOfPerson () { 
    char doneBuffer[5] = "DONE";
    Person idil;
    idil.name = getStringFromStream();
    *GRADING << "Received value for idil.name of type string - message: \"" << idil.name << "\", length: " << idil.name.length() + 1 << endl;

    idil.age = stoi(getStringFromStream());
    *GRADING << "Received value " << idil.age << " (of type int in string form) for idil.age" << endl;

    *GRADING << "Function sReturnAgeOfPerson invoked locally" << endl;
    string retVal = sReturnAgeOfPerson(idil);
    RPCSTUBSOCKET->write(retVal.c_str(), retVal.length() + 1);
    *GRADING << "Sending value of retVal of type string - message: \"" << retVal << "\", length: " << retVal.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function sReturnAgeOfPerson invocation done"<< endl;
}

void __sReturnAgeOfRelativeOfPerson () { 
    char doneBuffer[5] = "DONE";
    Relative idils_sister;
    idils_sister.name = getStringFromStream();
    *GRADING << "Received value for idils_sister.name of type string - message: \"" << idils_sister.name << "\", length: " << idils_sister.name.length() + 1 << endl;

    idils_sister.age = stoi(getStringFromStream());
    *GRADING << "Received value " << idils_sister.age << " (of type int in string form) for idils_sister.age" << endl;

    idils_sister.r.name = getStringFromStream();
    *GRADING << "Received value for idils_sister.r.name of type string - message: \"" << idils_sister.r.name << "\", length: " << idils_sister.r.name.length() + 1 << endl;

    idils_sister.r.age = stoi(getStringFromStream());
    *GRADING << "Received value " << idils_sister.r.age << " (of type int in string form) for idils_sister.r.age" << endl;

    *GRADING << "Function sReturnAgeOfRelativeOfPerson invoked locally" << endl;
    string retVal = sReturnAgeOfRelativeOfPerson(idils_sister);
    RPCSTUBSOCKET->write(retVal.c_str(), retVal.length() + 1);
    *GRADING << "Sending value of retVal of type string - message: \"" << retVal << "\", length: " << retVal.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function sReturnAgeOfRelativeOfPerson invocation done"<< endl;
}

void __sReturnAverageAgeOfFamilies () { 
    char doneBuffer[5] = "DONE";
    FamilyOfThree fot[5];
    
    for (int i0 = 0; i0 < 5; i0++) { 
        fot[i0].lastname = getStringFromStream();
        *GRADING << "Received value for fot[" << i0 << "].lastname of type string - message: \"" << fot[i0].lastname << "\", length: " << fot[i0].lastname.length() + 1 << endl;

        
        for (int i1 = 0; i1 < 3; i1++) { 
            fot[i0].family_members[i1].name = getStringFromStream();
            *GRADING << "Received value for fot[" << i0 << "].family_members[" << i1 << "].name of type string - message: \"" << fot[i0].family_members[i1].name << "\", length: " << fot[i0].family_members[i1].name.length() + 1 << endl;

            fot[i0].family_members[i1].age = stoi(getStringFromStream());
            *GRADING << "Received value " << fot[i0].family_members[i1].age << " (of type int in string form) for fot[" << i0 << "].family_members[" << i1 << "].age" << endl;

        }


    }


    *GRADING << "Function sReturnAverageAgeOfFamilies invoked locally" << endl;
    string retVal = sReturnAverageAgeOfFamilies(fot);
    RPCSTUBSOCKET->write(retVal.c_str(), retVal.length() + 1);
    *GRADING << "Sending value of retVal of type string - message: \"" << retVal << "\", length: " << retVal.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function sReturnAverageAgeOfFamilies invocation done"<< endl;
}

void __sReturnAverageAgeOfFamily () { 
    char doneBuffer[5] = "DONE";
    FamilyOfThree fot;
    fot.lastname = getStringFromStream();
    *GRADING << "Received value for fot.lastname of type string - message: \"" << fot.lastname << "\", length: " << fot.lastname.length() + 1 << endl;

    
    for (int i0 = 0; i0 < 3; i0++) { 
        fot.family_members[i0].name = getStringFromStream();
        *GRADING << "Received value for fot.family_members[" << i0 << "].name of type string - message: \"" << fot.family_members[i0].name << "\", length: " << fot.family_members[i0].name.length() + 1 << endl;

        fot.family_members[i0].age = stoi(getStringFromStream());
        *GRADING << "Received value " << fot.family_members[i0].age << " (of type int in string form) for fot.family_members[" << i0 << "].age" << endl;

    }


    *GRADING << "Function sReturnAverageAgeOfFamily invoked locally" << endl;
    string retVal = sReturnAverageAgeOfFamily(fot);
    RPCSTUBSOCKET->write(retVal.c_str(), retVal.length() + 1);
    *GRADING << "Sending value of retVal of type string - message: \"" << retVal << "\", length: " << retVal.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function sReturnAverageAgeOfFamily invocation done"<< endl;
}

void __sReturnAverageAgeOfPeople () { 
    char doneBuffer[5] = "DONE";
    Person people[5][4];
    
    for (int i0 = 0; i0 < 5; i0++) { 
        
        for (int i1 = 0; i1 < 4; i1++) { 
            people[i0][i1].name = getStringFromStream();
            *GRADING << "Received value for people[" << i0 << "][" << i1 << "].name of type string - message: \"" << people[i0][i1].name << "\", length: " << people[i0][i1].name.length() + 1 << endl;

            people[i0][i1].age = stoi(getStringFromStream());
            *GRADING << "Received value " << people[i0][i1].age << " (of type int in string form) for people[" << i0 << "][" << i1 << "].age" << endl;

        }

    }


    *GRADING << "Function sReturnAverageAgeOfPeople invoked locally" << endl;
    string retVal = sReturnAverageAgeOfPeople(people);
    RPCSTUBSOCKET->write(retVal.c_str(), retVal.length() + 1);
    *GRADING << "Sending value of retVal of type string - message: \"" << retVal << "\", length: " << retVal.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function sReturnAverageAgeOfPeople invocation done"<< endl;
}

void __sReturnAverageAgeOfPersons () { 
    char doneBuffer[5] = "DONE";
    Person persons[5];
    
    for (int i0 = 0; i0 < 5; i0++) { 
        persons[i0].name = getStringFromStream();
        *GRADING << "Received value for persons[" << i0 << "].name of type string - message: \"" << persons[i0].name << "\", length: " << persons[i0].name.length() + 1 << endl;

        persons[i0].age = stoi(getStringFromStream());
        *GRADING << "Received value " << persons[i0].age << " (of type int in string form) for persons[" << i0 << "].age" << endl;

    }


    *GRADING << "Function sReturnAverageAgeOfPersons invoked locally" << endl;
    string retVal = sReturnAverageAgeOfPersons(persons);
    RPCSTUBSOCKET->write(retVal.c_str(), retVal.length() + 1);
    *GRADING << "Sending value of retVal of type string - message: \"" << retVal << "\", length: " << retVal.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function sReturnAverageAgeOfPersons invocation done"<< endl;
}

void __sReturnInputFloat () { 
    char doneBuffer[5] = "DONE";
    float input = stof(getStringFromStream());
    *GRADING << "Received value " << input << " (of type float in string form) for input" << endl;

    *GRADING << "Function sReturnInputFloat invoked locally" << endl;
    string retVal = sReturnInputFloat(input);
    RPCSTUBSOCKET->write(retVal.c_str(), retVal.length() + 1);
    *GRADING << "Sending value of retVal of type string - message: \"" << retVal << "\", length: " << retVal.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function sReturnInputFloat invocation done"<< endl;
}

void __sReturnInputInt () { 
    char doneBuffer[5] = "DONE";
    int input = stoi(getStringFromStream());
    *GRADING << "Received value " << input << " (of type int in string form) for input" << endl;

    *GRADING << "Function sReturnInputInt invoked locally" << endl;
    string retVal = sReturnInputInt(input);
    RPCSTUBSOCKET->write(retVal.c_str(), retVal.length() + 1);
    *GRADING << "Sending value of retVal of type string - message: \"" << retVal << "\", length: " << retVal.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function sReturnInputInt invocation done"<< endl;
}

void __sReturnInputString () { 
    char doneBuffer[5] = "DONE";
    string input = getStringFromStream();
    *GRADING << "Received value for input of type string - message: \"" << input << "\", length: " << input.length() + 1 << endl;

    *GRADING << "Function sReturnInputString invoked locally" << endl;
    string retVal = sReturnInputString(input);
    RPCSTUBSOCKET->write(retVal.c_str(), retVal.length() + 1);
    *GRADING << "Sending value of retVal of type string - message: \"" << retVal << "\", length: " << retVal.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function sReturnInputString invocation done"<< endl;
}

void __sReturnTwo () { 
    char doneBuffer[5] = "DONE";
    *GRADING << "Function sReturnTwo invoked locally" << endl;
    string retVal = sReturnTwo();
    RPCSTUBSOCKET->write(retVal.c_str(), retVal.length() + 1);
    *GRADING << "Sending value of retVal of type string - message: \"" << retVal << "\", length: " << retVal.length() + 1 << endl;

    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer));
    *GRADING << "Function sReturnTwo invocation done"<< endl;
}

void dispatchFunction () { 
    string functionName = getStringFromStream();
    if (!RPCSTUBSOCKET-> eof()) {
        if (functionName == "sReturnTwo") {
            __sReturnTwo();
        } else if (functionName == "sReturnInputString") {
            __sReturnInputString();
        } else if (functionName == "sReturnInputInt") {
            __sReturnInputInt();
        } else if (functionName == "sReturnInputFloat") {
            __sReturnInputFloat();
        } else if (functionName == "sReturnAverageAgeOfPersons") {
            __sReturnAverageAgeOfPersons();
        } else if (functionName == "sReturnAverageAgeOfPeople") {
            __sReturnAverageAgeOfPeople();
        } else if (functionName == "sReturnAverageAgeOfFamily") {
            __sReturnAverageAgeOfFamily();
        } else if (functionName == "sReturnAverageAgeOfFamilies") {
            __sReturnAverageAgeOfFamilies();
        } else if (functionName == "sReturnAgeOfRelativeOfPerson") {
            __sReturnAgeOfRelativeOfPerson();
        } else if (functionName == "sReturnAgeOfPerson") {
            __sReturnAgeOfPerson();
        } else if (functionName == "returnYoungestMember") {
            __returnYoungestMember();
        } else if (functionName == "returnYoungestAveragePeople") {
            __returnYoungestAveragePeople();
        } else if (functionName == "returnTwo") {
            __returnTwo();
        } else if (functionName == "returnRelativeAYearOlder") {
            __returnRelativeAYearOlder();
        } else if (functionName == "returnOldestMember") {
            __returnOldestMember();
        } else if (functionName == "returnOldestFamily") {
            __returnOldestFamily();
        } else if (functionName == "returnOldestAverageFamily") {
            __returnOldestAverageFamily();
        } else if (functionName == "returnInputString") {
            __returnInputString();
        } else if (functionName == "returnInputInt") {
            __returnInputInt();
        } else if (functionName == "returnInputFloat") {
            __returnInputFloat();
        } else if (functionName == "returnAverageAgeOfPersons") {
            __returnAverageAgeOfPersons();
        } else if (functionName == "returnAverageAgeOfPeople") {
            __returnAverageAgeOfPeople();
        } else if (functionName == "returnAverageAgeOfFamily") {
            __returnAverageAgeOfFamily();
        } else if (functionName == "returnAverageAgeOfFamilies") {
            __returnAverageAgeOfFamilies();
        } else if (functionName == "returnAgeOfRelativeOfPerson") {
            __returnAgeOfRelativeOfPerson();
        } else if (functionName == "returnAgeOfPerson") {
            __returnAgeOfPerson();
        } else if (functionName == "printTwo") {
            __printTwo();
        } else if (functionName == "printThis") {
            __printThis();
        } else if (functionName == "printRelative") {
            __printRelative();
        } else if (functionName == "printPersonsOfPersons") {
            __printPersonsOfPersons();
        } else if (functionName == "printPersons") {
            __printPersons();
        } else if (functionName == "printPerson") {
            __printPerson();
        } else if (functionName == "printOne") {
            __printOne();
        } else if (functionName == "printNone") {
            __printNone();
        } else if (functionName == "printFamily") {
            __printFamily();
        } else if (functionName == "printFamilies") {
            __printFamilies();
        } else if (functionName == "makeRandomPerson") {
            __makeRandomPerson();
        } else if (functionName == "makePersonWithName") {
            __makePersonWithName();
        } else if (functionName == "makePersonAgeYearsOld") {
            __makePersonAgeYearsOld();
        } else if (functionName == "makePersonAgeAndAHalfYearsOld") {
            __makePersonAgeAndAHalfYearsOld();
        } else if (functionName == "makeFamilyWithPersons") {
            __makeFamilyWithPersons();
        } else if (functionName == "makeFamilyWithPersonArray") {
            __makeFamilyWithPersonArray();
        } else if (functionName == "makeFamilyWithName") {
            __makeFamilyWithName();
        } else if (functionName == "makeFamilyWithAges") {
            __makeFamilyWithAges();
        } else if (functionName == "makeFamilyOfThree") {
            __makeFamilyOfThree();
        } else if (functionName == "makeCopyOfPerson") {
            __makeCopyOfPerson();
        } else if (functionName == "fReturnTwo") {
            __fReturnTwo();
        } else if (functionName == "fReturnInputString") {
            __fReturnInputString();
        } else if (functionName == "fReturnInputInt") {
            __fReturnInputInt();
        } else if (functionName == "fReturnInputFloat") {
            __fReturnInputFloat();
        } else if (functionName == "fReturnAverageAgeOfPersons") {
            __fReturnAverageAgeOfPersons();
        } else if (functionName == "fReturnAverageAgeOfPeople") {
            __fReturnAverageAgeOfPeople();
        } else if (functionName == "fReturnAverageAgeOfFamily") {
            __fReturnAverageAgeOfFamily();
        } else if (functionName == "fReturnAverageAgeOfFamilies") {
            __fReturnAverageAgeOfFamilies();
        } else if (functionName == "fReturnAgeOfRelativeOfPerson") {
            __fReturnAgeOfRelativeOfPerson();
        } else if (functionName == "fReturnAgeOfPerson") {
            __fReturnAgeOfPerson();
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
