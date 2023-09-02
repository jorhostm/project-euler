#include <stdio.h>
#include <stdlib.h>

static long long C(long long n, int *mem)
{
        if (n > 3000000)
        {
            long long n_1 = n % 2 ? 3*n+1 : n / 2;
            return C(n_1, mem) + 1;
        }
        
        if (mem[n])
            return mem[n];
        
        long long n_1 = n % 2 ? 3*n+1 : n / 2;
        mem[n] = C(n_1, mem) + 1;
        return mem[n];   
}

void problem14()
{
    int *mem = (int *) calloc(3000500, sizeof(int));
    mem[1] = 1;
    long long max = 1;
    long long max_n = 1;
    
    for (int n = 2; n < 1000000; n++)
    {
        long long N = C(n,mem);
        if (N > max)
        {
            max = N;
            max_n = n;
        }
    }

    printf("Problem 14:\t%lld\n", max_n);
    free(mem);
}