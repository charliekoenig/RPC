#include "testarray2.idl"
#include <cstdio>

using namespace std;

int sqrt(int x[24], int y[24][15], int z[24][15]) {
        for (int i = 0; i < 24; i++) {
                printf("%d", x[i]);
                for (int j = 0; j < 15; j++) {
                        printf(" %d %d", y[i][j], z[i][j]);
                }
                printf("\n");

        }

        return x[23];
}

