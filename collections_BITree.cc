#include <iostream>
#include <memory.h> 
#include <cstdio>
using namespace std;
const int MAX = 32002;
int stars[MAX];
int level[MAX];
int lowbit(int x)
{
    return x & -x;
}

int sum(int x)
{
    int sum = 0;
    while(x)
    {
        sum += stars[x];
        x -= lowbit(x);
    }
    return sum;
}

void update(int x, int val)
{
    while(x < MAX)
    {
        stars[x] += val;
        x += lowbit(x);
    }
}
/**
 * 二维树状数组
 */
int C[MAX][MAX];
void update2(int x, int y, int val)
{
    for(int i = x; i <= MAX; i += lowbit(i))
        for(int j = y; j <= MAX; j += lowbit(j))
            C[i][j] += val;
}

int sum2(int x, int y)
{
    int res = 0;
    for(int i = x; i > 0; i -= lowbit(i))
        for(int j = y; j > 0; j -= lowbit(j))
            res +=  C[i][j];
    return res;
}

int main()
{
    int n, x, y;
    while(cin >> n && n)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &x, &y);
            level[sum( x + 1 )]++;
            update(x + 1, 1);
        }
        for(int i = 0; i < n; i++)
            printf("%d\n", level[i]);
    }
    return 0;
}
