#include <stdio.h>
#include <time.h>

#include "main.h"

int main(void)
{
    for (size_t i = 0; i < sizeof(problems)/sizeof(problems[0]); i++)
    {
        struct timespec start, stop;
        timespec_get(&start, TIME_UTC);
        problems[i]();
        timespec_get(&stop, TIME_UTC);
        long t = (stop.tv_sec - start.tv_sec) * 1000000000L + (stop.tv_nsec - start.tv_nsec);
        printf("\t%6ld us\n", t/1000);
    }
    
    return 0;
}
