#include <stdio.h>

static int get_num_length(int n)
{
    int nineteen[20] = {0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8};
    if (n < 20)
        return nineteen[n];
    
    int ninety[10] = {0,0,6,6,5,5,5,7,6,6};
    if (n < 100 && n >= 20)
        return ninety[n/10] + nineteen[n % 10];

    if (n >= 100 && n < 1000){
        int sum = nineteen[n/100] + 7;
        int rest = n%100;

        if (rest != 0)
        {
            sum += 3;
            if (rest < 20)
                sum += nineteen[rest];
            else
                sum += ninety[rest / 10] + nineteen[rest % 10];
        }
        
        return sum;
    }

    if (n == 1000)
        return 11;
    
    printf("ONONONONONO");
    return 0;
}

void problem17()
{
    int sum = 0;
    for (int i = 0; i <= 1000; i++)
    {
        int n = get_num_length(i);
        sum += n;
    }  
    printf("Problem 17:\t%d\n", sum);
}