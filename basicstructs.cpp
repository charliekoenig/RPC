#include "basicstructs.idl"

#include <cstdio>

int oldestAge(StructWithArrays x[10]) {
        int maxAge = -1;
        // Person p = x[0].people[0];
        for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                        int currAge = x[i].people[j].age;
                        printf("[%d][%d]: %d\n", i, j, currAge);
                        if (currAge > maxAge) {
                                maxAge = currAge;
                                // p.firstname = x[i].people[j].firstname;
                                // p.lastname = x[i].people[j].lastname;
                                // p.age = x[i].people[j].age;
                        }
                }
        }

        printf("oldest age in the server is: %d\n", maxAge);

        return maxAge;
}