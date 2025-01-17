#include "../jemalloc/include/jemalloc/jemalloc.h"
#include <stdio.h>

int main() {
	int* arr = (int*)je_calloc(5, sizeof(int));
	arr[0] = 1;
	for (int i = 0; i < 5; i++) {
		printf("%d\n", arr[i]);
	}
	je_free(arr);
}