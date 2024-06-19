#include <stdio.h>

#define N 1000000
#define SIEVE_LEN N/(sizeof(int)*8)

#define SET_BIT(buf,n) ((buf[(n)/(sizeof(int)*8)]) |= 1<<((n)%(sizeof(int)*8)))
#define CHECK_BIT(buf,n) ((buf[(n)/(sizeof(int)*8)]) & (1<<((n)%(sizeof(int)*8))))

#define N_PRIMES 78498

void problem35(void)
{
    // Initialise the sieve bitfield to 0
    int sieve[SIEVE_LEN] = {0};

    // Set the 0 and 1 bit, since they are not prime numbers
    SET_BIT(sieve, 0);
    SET_BIT(sieve, 1);

    // Array to hold prime numbers, and a counter
    int primes[N_PRIMES], p_cnt = 0;

    // Sieve of Eratosthenes
    for (int n = 2; n < N; n++)
    {
        // If n bit is set, means n is not prime. Skip
        if (CHECK_BIT(sieve, n))
            continue;

        // n is prime. Set bits of all multiples of n
        for (int i = n+n; i < N; i += n)
            SET_BIT(sieve, i);

        // Add n to array of primes and increment the counter
        primes[p_cnt++] = n;
    }

    // Check every prime number if they are circular. Skip n=2
    int cnt = 1;
    for(int *ptr = primes+1; ptr < primes+p_cnt; ptr++)
    {
        // Extract digits and store them in an array
        int digits[6], d_cnt = 0;
        for (int n = *ptr; n > 0; n /= 10)
            digits[d_cnt++] = n % 10;
        
        // Check if n has an even digit
        int is_admissible = 1;
        for (int i = 0; i < d_cnt; i++)
            is_admissible &= digits[i];
        
        // n can't be a circular prime if it contains an even digit (assuming n > 2)
        if (!is_admissible)
            continue;

        // Check if all other rotations of n are prime
        for (int i = 1; i < d_cnt; i++)
        {
            int num = 0;
            for (int j = 0, m = 1; j < d_cnt; j++, m *= 10)
                num += digits[(i+j) % d_cnt] * m;
            
            if (!CHECK_BIT(sieve, num))
            {
                is_admissible = 0;
                break;
            }
        }

        if (is_admissible)
            cnt++;

    }

    printf("Problem 35:\t%10d", cnt);
}
