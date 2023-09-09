#include <stdio.h>

void problem12()
{
    int tr = 1, n = 1, cnt = 1;
    while (cnt <= 500)
    {
       cnt = 0;
       tr += ++n;
       int high = tr;

        for (int low = 1; low < high; low++)
        {
            if (tr % low == 0)
            {
                high = tr / low;
                cnt += 1 + (high != low);
            }
        }
    }
    printf("Problem 12:\t%10d",tr);
}