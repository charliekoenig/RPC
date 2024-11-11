#include "testarray1.idl"
#include <cstdio>

using namespace std;

int sqrt(int x[24], int y[24]) {
        for (int i = 0; i < 24; i++) {
                if (x[i] == y[i]) {
                        printf("x (%d) and y (%d) are equal for index %d!\n", x[i], y[i], i);
                }
        }

        return x[23];
}

