#include <inttypes.h>
#include <stdio.h>

#define BASE 1000000000ULL
#define SZ 34

void problem16(void)
{
    uint64_t num[SZ] = {0};
    num[0] = 1;

    for (size_t i = 0; i < 125; i++)
    {
        uint64_t carry = 0;
        for (size_t j = 0; j < SZ; j++)
        {
            uint64_t product = num[j] * 256 + carry;
            carry = product / BASE;
            num[j] = product % BASE;
        }
    }

    int sum = 0;
    for (int i = SZ-1; i >= 0; i--)
    {
        char buf[32];
        sprintf(buf, "%09llu", num[i]);
        for (size_t j = 0; j < 32; j++)
        {
            char c = buf[j];
            if (c == '\0')
                break;
            sum += c - '0';
        }
    }
    
    printf("Problem 16:\t%10d", sum);
}
