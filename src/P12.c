#include <stdio.h>

void problem12()
{
    int tr = 1;
    int n = 1;
    int count = 1;
    while (count <= 500)
    {
        count = 2;
        n++;
        tr += n;

        for (int i = 1; i < tr; i++)
        {
            if (tr % i == 0)
                count++;
        }
    }
    printf("Problem 12:\t%d\n",tr);
}