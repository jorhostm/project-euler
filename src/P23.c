#include <stdio.h>

#define N_MAX 28123

int is_abundant(int n)
{
    int sum = 1, high = n;
    for (int low = 2; low < high; low++)
    {
        if (n % low == 0)
        {
            high = n / low;
            sum += (high > low) ? low + high : low;
        }
    }
    return sum > n;
}

void problem23()
{
    int abundants[N_MAX] = {0};
    char subtracted[N_MAX] = {0};
    int num_abundants = 0;
    int sum = N_MAX * (N_MAX-1) / 2;

    for (int n = 12; n < N_MAX; n++)
    {
        if (is_abundant(n))
        {
            abundants[num_abundants++] = n;
            for (int i = 0; i < num_abundants; i++)
            {
                int npa = n + abundants[i];
                if (npa < N_MAX && !subtracted[npa])
                {
                    sum -= npa;
                    subtracted[npa] = 1;
                }
            }
        }
    }
    
    printf("Problem 23:\t%10d", sum);
}