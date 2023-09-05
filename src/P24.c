#include <stdio.h>

#define N_SYM 10
#define N_POS 1000000 - 1

void problem24()
{
    int symbols[N_SYM];
    for (int i = 0; i < N_SYM; i++)
        symbols[i] = i;
        
    char permutation[N_SYM+1] = {0};
    int n_perms = 1;
    for (int i = 1; i <= N_SYM; i++)
        n_perms *= i;
    
    int n = N_POS;

    for (int i = 0; i < N_SYM; i++)
    {
        n_perms /= N_SYM - i;
        const int k = n / n_perms;
        n = n % n_perms;
        int m = 0;
        for (int j = 0; j <= k; m++)
            j += (symbols[m] >= 0);
        permutation[i] = '0' + symbols[--m];
        symbols[m] = -1; 
    }
    

    printf("Problem 24:\t%s\n", permutation);
    return;
}