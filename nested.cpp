#include <string>
#include <cstdio>

using namespace std;
#include "nested.idl"

int testStruct(Outer obj) {
    // Access single nested struct
    printf("Single struct: x=%d, y=%.2f, name=%s\n", 
           obj.data.x, obj.data.y, obj.data.name.c_str());
    
    // Access array of structs
    for(int i = 0; i < 3; i++) {
        printf("Array struct %d: x=%d, y=%.2f, name=%s\n",
               i, obj.array[i].x, obj.array[i].y, obj.array[i].name.c_str());
    }
    
    // Access 2D array
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("2D array[%d][%d]=%d\n", i, j, obj.nums[i][j]);
        }
    }
    
    return obj.data.x;
}

float testArray(Inner arr[4]) {
    float sum = 0;
    for(int i = 0; i < 4; i++) {
        sum += arr[i].y;
        printf("Array element %d: x=%d, y=%.2f, name=%s\n",
               i, arr[i].x, arr[i].y, arr[i].name.c_str());
    }
    return sum;
}

string testMixed(int simple[2], Inner structured[2]) {
    printf("Simple array: %d, %d\n", simple[0], simple[1]);
    
    for(int i = 0; i < 2; i++) {
        printf("Struct array %d: x=%d, y=%.2f, name=%s\n",
               i, structured[i].x, structured[i].y, structured[i].name.c_str());
    }
    
    return structured[0].name;
}