#include <stdio.h>

void problem19()
{
    int num[2][7] = {{2,2,2,1,3,1,1},{3,2,1,2,2,1,1}};
    int day = 0, count = 0;
    for (int year = 1901; year < 2001; year++)
    {
        int leap = (year % 4) == 0;
        count += num[leap][day];
        day = (day + 1 + leap) % 7;
    }
    printf("Problem 19:\t%10d", count);
}