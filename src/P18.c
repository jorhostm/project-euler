#include <stdio.h>

#define n 15
#define N n*(n+1)/2

void problem18()
{
    int vals[N];
    FILE *fp = fopen("data/18.txt", "r");
    for (int i = 0; i < N; i++)
        fscanf(fp, "%d", vals+i);
    fclose(fp);

    int *pos = vals + N - n;
    for (int row = n-1; row > 0; row--)
    {
        for (int i = 0; i < row; i++)
        {
            --pos;
            *pos += pos[row] >= pos[row+1] ? pos[row] : pos[row+1];
        }    
    }
    printf("Problem 18:\t%10d", *pos);
}