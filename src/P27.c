#include <stdio.h>
#include <string.h>

#define COEFF_LIMIT 1000
#define SIEVE_SZ 12990
#define PRIMES_SZ SIEVE_SZ/2

void problem27(void)
{
    int n_primes = 0, A = 0, B = 0, MAX = 0;
    int sieve[SIEVE_SZ], primes[PRIMES_SZ];
    memset(sieve, 0, SIEVE_SZ*sizeof(int));
    
    for (int p = 2; p < SIEVE_SZ; p++)
    {
        if (sieve[p])
            continue;
        primes[n_primes++] = p;
        for (int n = p+p; n < SIEVE_SZ; n += p)
            sieve[n] = 1;
    }

    for (int i = 0; i < n_primes; i++)
    {
        int b = primes[i];
        if (b > COEFF_LIMIT)
            break;
        for (int a = 1-COEFF_LIMIT; a < COEFF_LIMIT; a++)
        {
            int n = 1, y = 1 + a + b;
            while (y > 1 && !sieve[y])
            {
                n++;
                y = n*n + a*n + b;
            }

            if (n > MAX)
            {
                MAX = n;
                A = a;
                B = b;
            }
        }
    }

    printf("Problem 27:\t%10d", A*B);
}
