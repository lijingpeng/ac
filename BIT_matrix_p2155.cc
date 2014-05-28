#include <iostream>
#include <memory.h> 
#include <cstdio>
using namespace std;
const int MAX = 1010;
int C[MAX][MAX];

int lowbit(int x)
{
    return x & -x;
}

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
    int n, x, y, x2, y2;
    char ch[10];
    int t, m;
    cin >> n;
    while( n-- )
    {
        scanf("%d%d",&m, &t);
        memset(C, 0, sizeof(C));
        for(int p = 0; p < t; ++p)
        {
            scanf("%s", ch);
            if(ch[0] == 'C')
            {
                scanf("%d%d%d%d", &x, &y, &x2, &y2);
                update2(x, y, 1);
                update2(x2 + 1, y2 + 1, 1);
                update2(x, y2 + 1, 1);
                update2(x2 + 1, y, 1);
            }
            else
            {
                scanf("%d%d", &x, &y);
                int res = sum2(x, y);
                printf("%d\n", res & 1);
            }
        }
        if(n)
            printf("\n");
    }
    return 0;
}
