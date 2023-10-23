#include <stdio.h>

void problem28(void)
{
    int n = 1, sum = 1;
    for (int i = 3; i <= 1001; i+=2)
        for (int j = 0; j < 4; j++)
            n += i-1, sum += n;
    

    printf("Problem 28:\t%10d", sum);
}
