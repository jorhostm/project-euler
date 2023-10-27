#include <stdio.h>

#define N 200
#define N_COINS 8

int p[] = {1, 2, 5, 10, 20, 50, 100, 200};
int memo[N+1][N_COINS] = {0};

int f(int n, int k)
{
    if (n < 0 || k < 0)
        return 0;
        
    if (n == 0)
        return 1;

    if (k == 0)
        return n % p[0] == 0;
    
    if (!memo[n][k])
        memo[n][k] = f(n-p[k], k) + f(n, k-1);
    
    return memo[n][k];
}

void problem31(void)
{
    printf("Problem 31:\t%10d", f(N, N_COINS-1));
}
