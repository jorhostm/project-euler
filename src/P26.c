#include <stdio.h>
#include <string.h>

void problem26(void)
{
    int max = 0, max_d, nums[1000];
    for (int d = 1; d < 1000; d++)
    {
        memset(nums, 0, sizeof(nums));
        int n = 1, i = 1;
        while (!nums[n])
        {
            nums[n] = i++ - nums[n];
            n *= 10;
            if (n >= d)
                n %= d;
        }
        
        if (max < i - nums[n])
        {
            max = i - nums[n];
            max_d = d;
        }
    }
    printf("Problem 26:\t%10d", max_d);
}
