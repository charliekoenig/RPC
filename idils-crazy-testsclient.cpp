#include "rpcproxyhelper.h"
#include <string>
#include <iostream>
using namespace std;
#include "idils-crazy-tests.idl" // Replace with your actual .idl filename

void displayPerson(Person p) {
    cout << "Name: " << p.name << ", Age: " << p.age << endl;
}

void displayFamily(FamilyOfThree family) {
    cout << "Family Lastname: " << family.lastname << endl;
    cout << "Family Members:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "  - ";
        displayPerson(family.family_members[i]);
    }
    cout << endl;
}

FamilyOfThree createFamily(const string &lastname, Person p1, Person p2, Person p3) {
    FamilyOfThree family;
    family.lastname = lastname;
    family.family_members[0] = p1;
    family.family_members[1] = p2;
    family.family_members[2] = p3;
    return family;
}

int main(int argc, char *argv[]) {
    rpcproxyinitialize(argv[1]);

    Person idil = {"Idil Kolabas", 22};
    Relative idils_sister = {"Sister Kolabas", 25, idil};
    FamilyOfThree fot = {"Kolabas", {{"Idil", 22}, {"Sister", 25}, {"Parent", 50}}};
    Person persons[5] = {{"Alice", 30}, {"Bob", 35}, {"Charlie", 40}, {"David", 45}, {"Eve", 50}};
    Person people[5][4] = {
        {{"Alice", 30}, {"Bob", 31}, {"Charlie", 32}, {"David", 33}},
        {{"Eve", 34}, {"Frank", 35}, {"Grace", 36}, {"Hank", 37}},
        {{"Ivy", 38}, {"Jack", 39}, {"Kathy", 40}, {"Larry", 41}},
        {{"Mia", 42}, {"Nancy", 43}, {"Oscar", 44}, {"Paul", 45}},
        {{"Quinn", 46}, {"Rachel", 47}, {"Steve", 48}, {"Tina", 49}}
    };
    FamilyOfThree families[5] = {
        {"Smith", {{"John", 40}, {"Jane", 38}, {"Jack", 15}}},
        {"Doe", {{"Joe", 42}, {"Jill", 39}, {"Jenny", 16}}},
        {"Brown", {{"Jim", 45}, {"Joan", 43}, {"Josh", 18}}},
        {"Taylor", {{"Tim", 50}, {"Tina", 48}, {"Tom", 20}}},
        {"White", {{"Will", 55}, {"Wendy", 52}, {"Walter", 25}}}
    };


    // void
    printNone();
    printOne(42);
    printTwo(3.14);
    printThis("Hello, distributed world!");
    printPerson(idil);
    printRelative(idils_sister);
    printFamily(fot);
    printPersons(persons);
    printFamilies(families);
    printPersonsOfPersons(people);

    // int returning tests
    cout << "returnTwo: " << returnTwo() << endl;
    cout << "returnInputInt(42): " << returnInputInt(42) << endl;
    cout << "returnInputFloat(3.14): " << returnInputFloat(3.14) << endl;
    cout << "returnInputStringLength(\"Hello\"): " << returnInputString("Hello") << endl;
    cout << "returnAgeOfPerson(Idil): " << returnAgeOfPerson(idil) << endl;
    cout << "returnAgeOfRelativeOfPerson(Idil's Sister): " 
         << returnAgeOfRelativeOfPerson(idils_sister) << endl;
    cout << "returnAverageAgeOfFamily(Kolabas): " 
         << returnAverageAgeOfFamily(fot) << endl;
    cout << "returnAverageAgeOfPersons: " << returnAverageAgeOfPersons(persons) << endl;
    cout << "returnAverageAgeOfFamilies: " 
         << returnAverageAgeOfFamilies(families) << endl;
    cout << "returnAverageAgeOfPeople: " << returnAverageAgeOfPeople(people) << endl;

    // float returning tests
    cout << "returnTwo: " << fReturnTwo() << endl;
    cout << "returnInputInt(42): " << fReturnInputInt(42) << endl;
    cout << "returnInputFloat(3.14): " << fReturnInputFloat(3.14) << endl;
    cout << "returnInputStringLength(\"Hello\"): " << fReturnInputString("Hello") << endl;
    cout << "returnAgeOfPerson(Idil): " << fReturnAgeOfPerson(idil) << endl;
    cout << "returnAgeOfRelativeOfPerson(Idil's Sister): " 
         << fReturnAgeOfRelativeOfPerson(idils_sister) << endl;
    cout << "returnAverageAgeOfFamily(Kolabas): " 
         << fReturnAverageAgeOfFamily(fot) << endl;
    cout << "returnAverageAgeOfPersons: " << fReturnAverageAgeOfPersons(persons) << endl;
    cout << "returnAverageAgeOfFamilies: " 
         << fReturnAverageAgeOfFamilies(families) << endl;
    cout << "returnAverageAgeOfPeople: " << fReturnAverageAgeOfPeople(people) << endl;

    // string returning tests
    cout << sReturnTwo() << endl;
    cout << sReturnInputInt(42) << endl;
    cout << sReturnInputFloat(3.14) << endl;
    cout << sReturnInputString("Hello, distributed world!") << endl;
    cout << sReturnAgeOfPerson(idil) << endl;
    cout << sReturnAgeOfRelativeOfPerson(idils_sister) << endl;
    cout << sReturnAverageAgeOfFamily(fot) << endl;
    cout << sReturnAverageAgeOfPersons(persons) << endl;
    cout << sReturnAverageAgeOfFamilies(families) << endl;
    cout << sReturnAverageAgeOfPeople(people) << endl;

    // struct returning tests - Person
    Person randomPerson = makeRandomPerson();
    cout << "Random Person: ";
    displayPerson(randomPerson);

    Person personAge = makePersonAgeYearsOld(30);
    cout << "Person Age 30: ";
    displayPerson(personAge);

    Person personHalfAge = makePersonAgeAndAHalfYearsOld(25.5);
    cout << "Person Age 25.5: ";
    displayPerson(personHalfAge);

    Person namedPerson = makePersonWithName("Idil Kolabas");
    cout << "Named Person: ";
    displayPerson(namedPerson);

    Person copyPerson = makeCopyOfPerson(namedPerson);
    cout << "Copy of Person: ";
    displayPerson(copyPerson);

    Person olderRelative = returnRelativeAYearOlder(idils_sister);
    cout << "Relative a year older: ";
    displayPerson(olderRelative);

    Person oldestMember = returnOldestMember(fot);
    cout << "Oldest member of family: ";
    displayPerson(oldestMember);

    Person youngestMember = returnYoungestMember(persons);
    cout << "Youngest member of persons: ";
    displayPerson(youngestMember);

    Person oldestAvgFamily = returnOldestAverageFamily(families);
    cout << "Oldest average family member: ";
    displayPerson(oldestAvgFamily);

    Person youngestAvgPeople = returnYoungestAveragePeople(people);
    cout << "Youngest average people: ";
    displayPerson(youngestAvgPeople);

    // struct returning tests - People or FoT
    FamilyOfThree randomFamily = makeFamilyOfThree();
    cout << "Random Family of Three:" << endl;
    displayFamily(randomFamily);

    FamilyOfThree ageFamily = makeFamilyWithAges(25, 35, 45);
    cout << "Family with Ages 25, 35, 45:" << endl;
    displayFamily(ageFamily);

    FamilyOfThree namedFamily = makeFamilyWithName("Kolabas");
    cout << "Family with Lastname Kolabas:" << endl;
    displayFamily(namedFamily);

    Person p1 = {"Alice", 30};
    Person p2 = {"Bob", 28};
    Person p3 = {"Charlie", 5};
    FamilyOfThree personFamily = makeFamilyWithPersons(p1, p2, p3);
    cout << "Family with Specific Persons:" << endl;
    displayFamily(personFamily);

    Person fofthree[3] = {{"Dave", 45}, {"Eve", 40}, {"Frank", 10}};
    FamilyOfThree arrayFamily = makeFamilyWithPersonArray(fofthree);
    cout << "Family with Persons Array:" << endl;
    displayFamily(arrayFamily);

    FamilyOfThree five_families[5] = {
        createFamily("Smith", {"John", 40}, {"Jane", 38}, {"Jack", 15}),
        createFamily("Doe", {"Joe", 42}, {"Jill", 39}, {"Jenny", 16}),
        createFamily("Brown", {"Jim", 45}, {"Joan", 43}, {"Josh", 18}),
        createFamily("Taylor", {"Tim", 50}, {"Tina", 48}, {"Tom", 20}),
        createFamily("White", {"Will", 55}, {"Wendy", 52}, {"Walter", 25})
    };
    FamilyOfThree oldestFamily = returnOldestFamily(five_families);
    cout << "Oldest Family based on Age Sum:" << endl;
    displayFamily(oldestFamily);

    return 0;
}
