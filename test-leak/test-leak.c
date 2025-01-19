// debug_malloc.cpp
// compile by using: cl /EHsc /W4 /D_DEBUG /MDd debug_malloc.cpp
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <stdio.h>

int main()
{
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
    printf("Hello World!\n");

    int* x = (int*)malloc(sizeof(int));

    *x = 7;

    printf("%d\n", *x);

    x = (int*)calloc(3, sizeof(int));
    x[0] = 7;
    x[1] = 77;
    x[2] = 777;

    printf("%d %d %d\n", x[0], x[1], x[2]);

    x = (int*)calloc(3, sizeof(int));
    x = (int*)calloc(3, sizeof(int));
    x = (int*)calloc(3, sizeof(int));
    x = (int*)calloc(3, sizeof(int));
    x = (int*)calloc(3, sizeof(int));
    x = (int*)calloc(3, sizeof(int));

    _CrtDumpMemoryLeaks();
    printf("%d %d %d\n", x[0], x[1], x[2]);
}
