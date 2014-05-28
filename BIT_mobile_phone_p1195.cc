#include <iostream>
#include <memory.h> 
#include <cstdio>
using namespace std;
const int MAX = 1025;

int lowbit(int x)
{
    return x & -x;
}

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
    int n, s, a, x, y;
    while(cin >> n && n != 3)
    {
        if(n == 0)
        {
            scanf("%d", &s);
            memset(C, 0, sizeof(C));
        }
        if(n == 1)
        {
            scanf("%d%d%d", &x, &y, &a);
            update2(x + 1, y + 1, a);
        }
        if(n == 2)
        {
            int x2, y2;
            scanf("%d%d%d%d", &x, &y, &x2, &y2);
            printf("%d\n", sum2(x2 + 1, y2 + 1) - sum2(x2 + 1, y) - sum2(x, y2 + 1) + sum2(x , y));
        }
    }
    return 0;
}
