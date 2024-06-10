#include <stdio.h>

#define N_max 2540160

const int factorials[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

void problem34(void)
{
    int total = 0;
    int num[] = {0,6,1,0,4,5,2};
    int n = N_max;

    for (int d = 7; d > 1; d--)
    {
        int N_lim = 1;
        for (int i = 1; i < d; i++)
            N_lim *= 10;
        
        while (n >= N_lim)
        {
            int fac_sum = 0;
            for (int i = 0; i < d; i++)
                fac_sum += factorials[num[i]];
            
            if (fac_sum == n)
                total += fac_sum;

            for (int i = 0; i < d; i++)
            {
                if (num[i] > 0)
                {
                    num[i]--;
                    break;
                }
                num[i] = 9;
            }
            n--;
        }
    }
    
    printf("Problem 34:\t%10d", total);
}
