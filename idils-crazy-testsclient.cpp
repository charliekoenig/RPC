#include "rpcproxyhelper.h"
#include <string>
#include <iostream>
using namespace std;
#include "idils-crazy-tests.idl" // Replace with your actual .idl filename

int main(int argc, char *argv[]) {
    rpcproxyinitialize(argv[1]);

    // Test each function

    // 1. Test printNone
    printNone();

    // 2. Test printOne
    printOne(42);

    // 3. Test printTwo
    printTwo(3.14);

    // 4. Test printThis
    printThis("Hello, distributed world!");

    // 5. Test printPerson
    Person idil = {"Idil Kolabas", 22};
    printPerson(idil);

    // 6. Test printRelative
    Relative idils_sister = {"Sister Kolabas", 25, idil};
    printRelative(idils_sister);

    // 7. Test printFamily
    FamilyOfThree fot = {"Kolabas", {{"Idil", 22}, {"Sister", 25}, {"Parent", 50}}};
    printFamily(fot);

    // 8. Test printPersons
    Person persons[5] = {{"Alice", 30}, {"Bob", 35}, {"Charlie", 40}, {"David", 45}, {"Eve", 50}};
    printPersons(persons);

    // 9. Test printFamilies
    FamilyOfThree families[5] = {
        {"Smith", {{"John", 40}, {"Jane", 38}, {"Jack", 15}}},
        {"Doe", {{"Joe", 42}, {"Jill", 39}, {"Jenny", 16}}},
        {"Brown", {{"Jim", 45}, {"Joan", 43}, {"Josh", 18}}},
        {"Taylor", {{"Tim", 50}, {"Tina", 48}, {"Tom", 20}}},
        {"White", {{"Will", 55}, {"Wendy", 52}, {"Walter", 25}}}
    };
    printFamilies(families);

    // 10. Test printPersonsOfPersons
    Person people[5][4] = {
        {{"Alice", 30}, {"Bob", 31}, {"Charlie", 32}, {"David", 33}},
        {{"Eve", 34}, {"Frank", 35}, {"Grace", 36}, {"Hank", 37}},
        {{"Ivy", 38}, {"Jack", 39}, {"Kathy", 40}, {"Larry", 41}},
        {{"Mia", 42}, {"Nancy", 43}, {"Oscar", 44}, {"Paul", 45}},
        {{"Quinn", 46}, {"Rachel", 47}, {"Steve", 48}, {"Tina", 49}}
    };
    printPersonsOfPersons(people);

    return 0;
}
