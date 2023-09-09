#include <stdio.h>
#include <time.h>

#include "main.h"

int main()
{
    for (int i = 0; i < sizeof(problems)/8; i++)
    {
        void (*f)() = problems[i];
        struct timespec start, stop;
        timespec_get(&start, TIME_UTC);
        f();
        timespec_get(&stop, TIME_UTC);
        long t = (stop.tv_sec - start.tv_sec) * 1000000000L + (stop.tv_nsec - start.tv_nsec);
        printf("\t%6ld us\n", t/1000);
    }
    
    return 0;
}