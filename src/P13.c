#include <stdio.h>

void problem13()
{
    FILE *fp = fopen("data/13.txt","r");
    char buf[52];
    signed char nums[60] = {0};
    while (!feof(fp))
    {
        fgets(buf, 52, fp);
        for (size_t i = 0; i < 50; i++)
        {
            int tmp = buf[49-i] - '0';
            int num = nums[59-i];
            int sum = tmp + num;
            nums[59-i] = sum % 10;
            nums[58-i] += sum / 10;
        }
        
    }
    printf("Problem 13:\t");
    int start = 0;
    for (; nums[start] == 0; start++);
    
    for (size_t i = start; i < start+9; i++)
        printf("%d", nums[i]);
}