#include <stdio.h>

#define N 5

void problem30(void)
{
    int sum = 0;
    int powers[11] = { 0 };
    powers[1] = 1;
    for (int i = 1; i < 10; powers[++i] = 1)
        for (int j = 0; j < N; j++)
            powers[i] *= i;
    
    for (int n = 2; n < 354294; n++)
    {
        int a = n/100000, b = (n%100000)/10000, c = (n%10000)/1000, d = (n%1000)/100, e = (n%100)/10, f = n%10;
        int powsum = powers[a] + powers[b] + powers[c] + powers[d] + powers[e] + powers[f];
        if (n == powsum)
            sum += n;   
    }
    printf("Problem 30:\t%10d", sum);
}
