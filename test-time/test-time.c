// crt_asctime_s.c
#include <time.h>
#include <stdio.h>

struct tm newtime;
__time32_t aclock;

int main(void)
{
    char buffer[32];
    errno_t errNum;
    _time32(&aclock);   // Get time in seconds.
    _localtime32_s(&newtime, &aclock);   // Convert time to struct tm form.

    // Print local time as a string.

    errNum = asctime_s(buffer, 32, &newtime);
    if (errNum)
    {
        printf("Error code: %d", (int)errNum);
        return 1;
    }
    printf("Current date and time: %s", buffer);
    getchar();
    return 0;
}