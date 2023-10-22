#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SZ 46448
#define N_NAMES 5163

int cmp(const void *lhs, const void *rhs)
{
    return strcmp(*(char **) lhs, *(char **) rhs);
}

int value(const char *name)
{
    int sum = 0;
    for (int i = 0; name[i] != '\0'; i++)
        sum += name[i] - 'A' + 1;
    return sum;
}

void problem22(void)
{
    char input[LINE_SZ];
    FILE *fp = fopen("data/names.txt", "r");
    assert(fp);
    fgets(input, LINE_SZ, fp);
    fclose(fp);
    char *names[N_NAMES];
    *names = strtok(input, "\",");
    for (int i = 1; i < N_NAMES; names[i++] = strtok(NULL, "\","));
    qsort(names, N_NAMES, sizeof(*names), &cmp);
    int sum = 0;
    for (int i = 0; i < N_NAMES; i++)
        sum += (i+1) * value(names[i]);
    
    printf("Problem 22:\t%10d", sum);
}
