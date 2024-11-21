#include <iostream>
#include <string>
using namespace std;
#include "idils-crazy-tests.idl"

void printNone() {
    cout << "No arguments provided!" << endl;
}

void printOne(int one) {
    cout << "Received int: " << one << endl;
}

void printTwo(float two) {
    cout << "Received float: " << two << endl;
}

void printThis(string thisStr) {
    cout << "Received string: " << thisStr << endl;
}

void printPerson(Person idil) {
    cout << "Person Name: " << idil.name << ", Age: " << idil.age << endl;
}

void printRelative(Relative idils_sister) {
    cout << "Relative Name: " << idils_sister.name
         << ", Age: " << idils_sister.age
         << ", Related Person: " << idils_sister.r.name
         << ", Age: " << idils_sister.r.age << endl;
}

void printFamily(FamilyOfThree fot) {
    cout << "Family Last Name: " << fot.lastname << endl;
    for (int i = 0; i < 3; i++) {
        cout << "  Member " << i + 1 << ": " << fot.family_members[i].name
             << ", Age: " << fot.family_members[i].age << endl;
    }
}

void printPersons(Person persons[5]) {
    for (int i = 0; i < 5; i++) {
        cout << "Person " << i + 1 << ": " << persons[i].name
             << ", Age: " << persons[i].age << endl;
    }
}

void printFamilies(FamilyOfThree fot[5]) {
    for (int i = 0; i < 5; i++) {
        cout << "Family " << i + 1 << ", Last Name: " << fot[i].lastname << endl;
        for (int j = 0; j < 3; j++) {
            cout << "  Member " << j + 1 << ": " << fot[i].family_members[j].name
                 << ", Age: " << fot[i].family_members[j].age << endl;
        }
    }
}

void printPersonsOfPersons(Person people[5][4]) {
    for (int i = 0; i < 5; i++) {
        cout << "Group " << i + 1 << ":" << endl;
        for (int j = 0; j < 4; j++) {
            cout << "  Person " << j + 1 << ": " << people[i][j].name
                 << ", Age: " << people[i][j].age << endl;
        }
    }
}
