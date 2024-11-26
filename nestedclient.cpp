#include <string>
#include <cstdio>
#include "rpcproxyhelper.h"
#include "c150grading.h"

using namespace std;
using namespace C150NETWORK;
#include "nested.idl"

int main(int argc, char *argv[]) {
    rpcproxyinitialize(argv[1]);

    // Test 1: Nested struct with arrays
    printf("\nTest 1: Nested struct with arrays\n");
    printf("----------------------------------\n");
    
    Outer test1;
    // Fill single struct
    test1.data.x = 1;
    test1.data.y = 1.1;
    test1.data.name = "single";
    
    // Fill array of structs
    for(int i = 0; i < 3; i++) {
        test1.array[i].x = i + 10;
        test1.array[i].y = i + 10.5;
        test1.array[i].name = "arr" + to_string(i);
    }
    
    // Fill 2D array
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            test1.nums[i][j] = i * 2 + j;
        }
    }
    
    int result1 = testStruct(test1);
    printf("Return value: %d\n\n", result1);
    
    // Test 2: Array of structs
    printf("Test 2: Array of structs\n");
    printf("-----------------------\n");
    
    Inner test2[4];
    for(int i = 0; i < 4; i++) {
        test2[i].x = i * 2;
        test2[i].y = i * 2.5;
        test2[i].name = "test" + to_string(i);
    }
    
    float result2 = testArray(test2);
    printf("Return value: %.2f\n\n", result2);
    
    // Test 3: Mixed arrays
    printf("Test 3: Mixed arrays\n");
    printf("-------------------\n");
    
    int test3a[2] = {42, 43};
    Inner test3b[2];
    for(int i = 0; i < 2; i++) {
        test3b[i].x = i + 100;
        test3b[i].y = i + 100.5;
        test3b[i].name = "mixed" + to_string(i);
    }
    
    string result3 = testMixed(test3a, test3b);
    printf("Return value: %s\n", result3.c_str());
    
    return 0;
}