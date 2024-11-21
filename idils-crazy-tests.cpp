#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
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

int returnTwo() {
    return 2;
}

int returnInputInt(int input) {
    return input;
}

int returnInputFloat(float input) {
    return static_cast<int>(input); 
}

int returnInputString(string input) {
    return input.length(); 
}

int returnAgeOfPerson(Person idil) {
    return idil.age;
}

int returnAgeOfRelativeOfPerson(Relative idils_sister) {
    return idils_sister.age;
}

int returnAverageAgeOfFamily(FamilyOfThree fot) {
    int totalAge = 0;
    for (int i = 0; i < 3; i++) {
        totalAge += fot.family_members[i].age;
    }
    return totalAge / 3; 
}

int returnAverageAgeOfPersons(Person persons[5]) {
    int totalAge = 0;
    for (int i = 0; i < 5; i++) {
        totalAge += persons[i].age;
    }
    return totalAge / 5; 
}

int returnAverageAgeOfFamilies(FamilyOfThree fot[5]) {
    int totalAge = 0, totalPeople = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            totalAge += fot[i].family_members[j].age;
            totalPeople++;
        }
    }
    return totalAge / totalPeople; 
}

int returnAverageAgeOfPeople(Person people[5][4]) {
    int totalAge = 0, totalPeople = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            totalAge += people[i][j].age;
            totalPeople++;
        }
    }
    return totalAge / totalPeople; 
}

float fReturnTwo() {
    return 2.5;
}

float fReturnInputInt(int input) {
    return static_cast<float>(input) + 0.5;
}

float fReturnInputFloat(float input) {
    return input; 
}

float fReturnInputString(string input) {
    return static_cast<float>(input.length()); 
}

float fReturnAgeOfPerson(Person idil) {
    return static_cast<float>(idil.age);
}

float fReturnAgeOfRelativeOfPerson(Relative idils_sister) {
    return static_cast<float>(idils_sister.age);
}

float fReturnAverageAgeOfFamily(FamilyOfThree fot) {
    float totalAge = 0;
    for (int i = 0; i < 3; i++) {
        totalAge += fot.family_members[i].age;
    }
    return totalAge / 3.0; 
}

float fReturnAverageAgeOfPersons(Person persons[5]) {
    float totalAge = 0;
    for (int i = 0; i < 5; i++) {
        totalAge += persons[i].age;
    }
    return totalAge / 5.0; 
}

float fReturnAverageAgeOfFamilies(FamilyOfThree fot[5]) {
    float totalAge = 0, totalPeople = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            totalAge += fot[i].family_members[j].age;
            totalPeople++;
        }
    }
    return totalAge / totalPeople; 
}

float fReturnAverageAgeOfPeople(Person people[5][4]) {
    float totalAge = 0, totalPeople = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            totalAge += people[i][j].age;
            totalPeople++;
        }
    }
    return totalAge / totalPeople; 
}


string intToString(int value) {
    ostringstream oss;
    oss << value;
    return oss.str();
}


string sReturnTwo() {
    return "2";
}

string sReturnInputInt(int input) {
    return intToString(input);
}

string sReturnInputFloat(float input) {
    ostringstream oss;
    oss << input; 
    return oss.str();
}

string sReturnInputString(string input) {
    return "Received string: " + input;
}

string sReturnAgeOfPerson(Person idil) {
    return "Age of Person " + idil.name + ": " + intToString(idil.age);
}

string sReturnAgeOfRelativeOfPerson(Relative idils_sister) {
    return "Age of Relative " + idils_sister.name + ": " + intToString(idils_sister.age);
}

string sReturnAverageAgeOfFamily(FamilyOfThree fot) {
    int totalAge = 0;
    for (int i = 0; i < 3; i++) {
        totalAge += fot.family_members[i].age;
    }
    int averageAge = totalAge / 3;
    return "Average age of family " + fot.lastname + ": " + intToString(averageAge);
}

string sReturnAverageAgeOfPersons(Person persons[5]) {
    int totalAge = 0;
    for (int i = 0; i < 5; i++) {
        totalAge += persons[i].age;
    }
    int averageAge = totalAge / 5;
    return "Average age of persons: " + intToString(averageAge);
}

string sReturnAverageAgeOfFamilies(FamilyOfThree fot[5]) {
    int totalAge = 0, totalPeople = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            totalAge += fot[i].family_members[j].age;
            totalPeople++;
        }
    }
    int averageAge = totalAge / totalPeople;
    return "Average age of families: " + intToString(averageAge);
}

string sReturnAverageAgeOfPeople(Person people[5][4]) {
    int totalAge = 0, totalPeople = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            totalAge += people[i][j].age;
            totalPeople++;
        }
    }
    int averageAge = totalAge / totalPeople;
    return "Average age of people: " + intToString(averageAge);
}

string randomName() {
    const string names[] = {"Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace"};
    int index = rand() % (sizeof(names) / sizeof(names[0]));
    return names[index];
}


Person makeRandomPerson() {
    srand(time(0));
    Person randomPerson = {randomName(), rand() % 100}; 
    return randomPerson;
}

Person makePersonAgeYearsOld(int age) {
    return {"Unnamed", age};
}

Person makePersonAgeAndAHalfYearsOld(float age) {
    return {"Unnamed", static_cast<int>(age)};
}

Person makePersonWithName(string name) {
    return {name, 0};
}

Person makeCopyOfPerson(Person p) {
    return p;
}

Person returnRelativeAYearOlder(Relative idils_sister) {
    Person olderRelative = {idils_sister.name, idils_sister.age + 1};
    return olderRelative;
}

Person returnOldestMember(FamilyOfThree fot) {
    Person oldest = fot.family_members[0];
    for (int i = 1; i < 3; i++) {
        if (fot.family_members[i].age > oldest.age) {
            oldest = fot.family_members[i];
        }
    }
    return oldest;
}

Person returnYoungestMember(Person persons[5]) {
    Person youngest = persons[0];
    for (int i = 1; i < 5; i++) {
        if (persons[i].age < youngest.age) {
            youngest = persons[i];
        }
    }
    return youngest;
}

Person returnOldestAverageFamily(FamilyOfThree fot[5]) {
    FamilyOfThree oldestFamily = fot[0];
    int maxAverageAge = 0;

    for (int i = 0; i < 5; i++) {
        int totalAge = 0;
        for (int j = 0; j < 3; j++) {
            totalAge += fot[i].family_members[j].age;
        }
        int averageAge = totalAge / 3;
        if (averageAge > maxAverageAge) {
            maxAverageAge = averageAge;
            oldestFamily = fot[i];
        }
    }

    return returnOldestMember(oldestFamily);
}

Person returnYoungestAveragePeople(Person people[5][4]) {
    Person youngestPerson = people[0][0];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (people[i][j].age < youngestPerson.age) {
                youngestPerson = people[i][j];
            }
        }
    }

    return youngestPerson;
}

Person createPerson(const string &name, int age) {
    return {name, age};
}

FamilyOfThree createFamily(const string &lastname, Person p1, Person p2, Person p3) {
    FamilyOfThree family;
    family.lastname = lastname;
    family.family_members[0] = p1;
    family.family_members[1] = p2;
    family.family_members[2] = p3;
    return family;
}

FamilyOfThree makeFamilyOfThree() {
    srand(time(0));
    return createFamily("Randomson", 
                        createPerson("Alice", rand() % 100),
                        createPerson("Bob", rand() % 100),
                        createPerson("Charlie", rand() % 100));
}

FamilyOfThree makeFamilyWithAges(int age1, int age2, int age3) {
    return createFamily("AgesFamily",
                        createPerson("Person1", age1),
                        createPerson("Person2", age2),
                        createPerson("Person3", age3));
}

FamilyOfThree makeFamilyWithName(string lastname) {
    return createFamily(lastname,
                        createPerson("Parent1", 40),
                        createPerson("Parent2", 38),
                        createPerson("Child", 12));
}

FamilyOfThree makeFamilyWithPersons(Person p1, Person p2, Person p3) {
    return createFamily("CustomFamily", p1, p2, p3);
}

FamilyOfThree makeFamilyWithPersonArray(Person fofthree[3]) {
    return createFamily("ArrayFamily", fofthree[0], fofthree[1], fofthree[2]);
}

FamilyOfThree returnOldestFamily(FamilyOfThree families[5]) {
    FamilyOfThree oldestFamily = families[0];
    int maxTotalAge = 0;

    for (int i = 0; i < 5; i++) {
        int totalAge = families[i].family_members[0].age +
                       families[i].family_members[1].age +
                       families[i].family_members[2].age;

        if (totalAge > maxTotalAge) {
            maxTotalAge = totalAge;
            oldestFamily = families[i];
        }
    }

    return oldestFamily;
}
