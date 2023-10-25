#include <stdio.h>

#define N 100

void problem29(void)
{
    int n_dups = 0, n_nums = 0;
    int pows[N+1] = {0}, nums[N];

    for (int n = 2; n*n <= N; n++)
        for (int pow = 2, nn = n*n; nn <= N; pow++, nn *= n)
            if (pows[nn] < pow)
            {
                pows[nn] = pow;
                nums[n_nums++] = nn;
            }
    
    for (int i = 0; i < n_nums; i++)
    {
        int a = nums[i];
        int pow = pows[a];
        for (int b = 2; b <= N; b++)
        {
            int prod = pow * b;
            for (int l = 1, r = prod; l < pow; l++, r = prod/l)
                if (prod % l == 0 && r <= N)
                {
                    // a^b is a duplicate
                    n_dups++;
                    break;
                }
        }  
    }
    printf("Problem 29:\t%10d", (N-1)*(N-1)-n_dups);
}
