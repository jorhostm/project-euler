#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>

int problem12()
{
    int tr = 1;
    int n = 1;
    int count = 1;
    while (count <= 500)
    {
        count = 2;
        n++;
        tr += n;

        for (int i = 1; i < tr; i++)
        {
            if (tr % i == 0)
                count++;
        }
    }
    return tr;
}

int problem13()
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

    for (size_t i = 0; i < 60; i++)
    {
        printf("%d", nums[i]);
    }
    printf("\n");
    return 69;
}

long long C(long long n, int *mem)
{
        if (n > 3000000)
        {
            long long n_1 = n % 2 ? 3*n+1 : n / 2;
            return C(n_1, mem) + 1;
        }
        
        if (mem[n])
            return mem[n];
        
        long long n_1 = n % 2 ? 3*n+1 : n / 2;
        mem[n] = C(n_1, mem) + 1;
        return mem[n];   
}

int problem14()
{
    int *mem = calloc(3000500, sizeof(int));
    mem[1] = 1;
    long long max = 1;
    long long max_n = 1;
    
    for (int n = 2; n < 1000000; n++)
    {
        long long N = C(n,mem);
        if (N > max)
        {
            max = N;
            max_n = n;
        }
    }

    return max_n;
    
}

int get_num_length(int n)
{
    int sum = 0;
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

int problem17()
{
    int sum = 0;
    for (int i = 0; i <= 1000; i++)
    {
        int n = get_num_length(i);
        sum += n;
        printf("%d\t%d\t%d\n", i, n, sum);
    }  
    return sum;
}

int find(int *arr, int pos, int lvl, int max_lvl, int cum_sum)
{
    if (lvl == max_lvl)
        return cum_sum + arr[pos];
    int sum1 = find(arr, pos + lvl, lvl + 1, max_lvl, cum_sum + arr[pos]);
    int sum2 = find(arr, pos + lvl + 1, lvl + 1, max_lvl, cum_sum + arr[pos]);
    return sum1 >= sum2 ? sum1 : sum2;
}
int problem18()
{
    const int n = 15;
    const int N = n*(n+1)/2;
    int vals[N] = {0};
    FILE *fp = fopen("data/18.txt", "r");
    for (int i = 0; i < N; i++)
        fscanf(fp, "%d", vals+i);
    fclose(fp);

    return find(vals, 0, 1, n, 0);
}

int problem67()
{
    const int n = 100;
    const int N = n*(n+1)/2;
    int vals[N];
    FILE *fp = fopen("data/67.txt", "r");
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
    return *pos;
}

int problem19()
{
    int num[2][7] = {{2,2,2,1,3,1,1},{3,2,1,2,2,1,1}};
    int day = 0, count = 0;
    for (int year = 1901; year < 2001; year++)
    {
        int leap = (year % 4) == 0;
        count += num[leap][day];
        day = (day + 1 + leap) % 7;
    }
    return count;
}

#include <inttypes.h>

#define BASE 1000000000ULL
#define SZ 18

int problem20()
{
    uint64_t num[SZ] = {0};
    num[0] = 1;

    for (size_t i = 2; i <= 100; i++)
    {
        uint64_t carry = 0;
        for (size_t j = 0; j < SZ; j++)
        {
            uint64_t product = num[j] * i + carry;
            carry = product / BASE;
            num[j] = product % BASE;
        }
    }

    int sum = 0;
    for (int i = SZ-1; i >= 0; i--)
    {
        char buf[18];
        sprintf(buf, "%09llu", num[i]);
        printf("%s", buf);
        for (size_t j = 0; j < 18; j++)
        {
            char c = buf[j];
            if (c == '\0')
                break;
            sum += c - '0';
        }
    }
    return sum;
}
#undef BASE
#undef SZ

int d(int n, int *arr)
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

int problem()
{
    int arr[30000] = {0};
    int sum = 0;
    
    for (int i = 2; i < 10000; i++)
        sum += i*(d(d(i,arr),arr) == i && d(i,arr) != i);
    
    return sum;
    
}

#endif