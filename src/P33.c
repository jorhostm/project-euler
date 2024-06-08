#include <stdio.h>

int gcd(int a, int b)
{
    while (b > 0)
    {
        int tmp = b;
        b = a%b;
        a = tmp;
    }

    return a;
}

void problem33(void)
{
    int numerator = 1;
    int denominator = 1;

    for (int a = 1; a <= 7; a++)
    {
        for (int c = a+1; c <= 8; c++)
        {
            for (int b = c+1; b <= 9; b++)
            {
                if (9*a*c - b*(10*a-c) == 0) {
                    numerator *= 10*a+b;
                    denominator *= 10*b+c;
                }
            }
        }
    }

    printf("Problem 33:\t%10d", denominator/gcd(denominator, numerator));
}
