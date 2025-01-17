#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "unistd.h"

void sleep(int x) {
	Sleep(x * 1000);
}