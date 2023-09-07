#include <stdio.h>

#define BASE 100000000000000000
#define N 59
typedef unsigned long long uint64_t;

void problem25()
{
    uint64_t a[N] = {0}, b[N] = {0}, c[N] = {0};
    uint64_t *f1 = a, *f2 = b, *f3 = c;
    f2[0] = 1;
    int n = 1, i = 1;

    while (f2[N-1] <= 10000000000000)
    {
        uint64_t carry = 0;
        for (int j = 0; j < n; j++)
        {
            f3[j] = f1[j] + f2[j] + carry;
            carry = f3[j] / BASE;
            f3[j] %= BASE; 
        }
        if (carry)
            f3[n++] = carry;
        i++;
        uint64_t *tmp = f1;
        f1 = f2;
        f2 = f3;
        f3 = tmp;
    }
    printf("Problem 25:\t%d\n", i);
}