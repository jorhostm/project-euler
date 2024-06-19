#include <stdio.h>

#define N 1000000
#define SIEVE_LEN N/(sizeof(int)*8)

#define SET_BIT(buf,n) ((buf[(n)/(sizeof(int)*8)]) |= 1<<((n)%(sizeof(int)*8)))
#define CHECK_BIT(buf,n) ((buf[(n)/(sizeof(int)*8)]) & (1<<((n)%(sizeof(int)*8))))

void problem35(void)
{
    int sieve[SIEVE_LEN] = {0};
    SET_BIT(sieve, 0);
    SET_BIT(sieve, 1);

    int sum = 0;

    for (int n = 0; n < N; n++)
    {
        if (CHECK_BIT(sieve, n))
            continue;
        
        for (int i = n+n; i < N; i += n)
            SET_BIT(sieve, i);

        sum++;
    }

    printf("Problem 35:\t%10d", sum);
}
