#include "../pthread-win32/pthread.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
//#include <unistd.h>
#include <windows.h>

// Let us create a global variable to change it in threads
int g = 0;

// The function to be executed by all threads
void* myThreadFun(void* vargp)
{
    // Store the value argument passed to this thread
    //int myid = getpid();
    DWORD win32_thread_id = GetCurrentThreadId();
    //pthread_t pthread_id = pthread_self();

    //printf("Win32 Thread ID: %lu\n", win32_thread_id);
    //printf("pthread ID: %lu\n", (unsigned long)pthread_id);

    // Let us create a static variable to observe its
    // changes
    static int s = 0;

    // Change static and global variables
    ++s;
    ++g;

    // Print the argument, static and global variables
    printf("Thread ID: %d, Static: %d, Global: %d\n", (unsigned long)win32_thread_id,
        ++s, ++g);
    Sleep(20 * 1000);
}

int main()
{
    int i;
    pthread_t tid;

    // Let us create three threads
    for (i = 0; i < 3; i++)
        pthread_create(&tid, NULL, myThreadFun, NULL);

    pthread_exit(NULL);
    return 0;
}
