#include <stdio.h>

static int d(int n, int *arr)
{
    int sum = arr[n];  
    int high = n*(sum == 0);
    sum -= high;
    for (int low = 1; low < high; low++)
    {
        int divisible = (n % low) == 0;
        sum += (low + (n / low)) * divisible;
        high = (n / low) * divisible + high * !divisible;
    }
    arr[n] = sum;
    return sum;
}

void problem21(void)
{
    int arr[30000] = {0};
    int sum = 0;
    
    for (int i = 2; i < 10000; i++)
        sum += i*(d(d(i,arr),arr) == i && d(i,arr) != i);
    
    printf("Problem 21:\t%10d", sum);
}
