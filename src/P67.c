#include <stdio.h>
#include <assert.h>

#define n 100
#define N n*(n+1)/2

void problem67(void)
{
    int vals[N];
    FILE *fp = fopen("data/67.txt", "r");
    assert(fp);
    
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
    printf("Problem 67:\t%10d", *pos);
}
