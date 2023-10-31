#include <stdio.h>

int isUnique(int num, int *visited)
{
    while (num) 
    { 
        if ((*visited) & (1 << (num%10))) 
            break; 
        *visited |= (1 << (num%10));
        num /= 10; 
    }
    return num == 0;
}

void problem32(void)
{
    int sum = 0;   
    for (int i = 2345; i <= 9876; i++)
    {
        int visited = 1;
        if (!isUnique(i, &visited))
            continue;
        for (int j = 2; j <= 98; j++)
        {
            int visited2 = visited;
            if (i % j == 0 && isUnique(j, &visited2) && isUnique(i / j, &visited2) && visited2 == 1023)
            {
                sum += i;
                break;
            }
        }     
    }

    printf("Problem 32:\t%10d", sum);
}
