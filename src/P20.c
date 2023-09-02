#include <stdio.h>
#include <inttypes.h>

#define BASE 1000000000ULL
#define SZ 18

void problem20()
{
    uint64_t num[SZ] = {0};
    num[0] = 1;

    for (size_t i = 2; i <= 100; i++)
    {
        uint64_t carry = 0;
        for (size_t j = 0; j < SZ; j++)
        {
            uint64_t product = num[j] * i + carry;
            carry = product / BASE;
            num[j] = product % BASE;
        }
    }

    int sum = 0;
    for (int i = SZ-1; i >= 0; i--)
    {
        char buf[18];
        sprintf(buf, "%09llu", num[i]);
        for (size_t j = 0; j < 18; j++)
        {
            char c = buf[j];
            if (c == '\0')
                break;
            sum += c - '0';
        }
    }
    printf("Problem 20:\t%d\n", sum);
}