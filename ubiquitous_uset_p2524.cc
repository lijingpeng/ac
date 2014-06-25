#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 50005;
int parent[MAXN];
int ranks[MAXN];
int n, res;

void make_set(int x)
{
    parent[x] = x;
    ranks[x]  = 0;
}

int find_set(int x)
{
    if(x != parent[x])
        parent[x] = find_set(parent[x]);
    return parent[x];
}

void union_set(int x, int y)
{
    x = find_set(x);
    y = find_set(y);
    if(x == y)
        return;
    res--;
    if(ranks[x] > ranks[y])
        parent[y] = x;
    else
    {
        parent[x] = y;
        if(ranks[x] == ranks[y])
            ranks[y]++;
    }
}

int main()
{
    int m, i, j = 1, x, y;
        while(scanf("%d%d", &n, &m))
                {
                        if(n == m && m == 0) break;
                        for(i = 1; i <= n; i++)
                            make_set(i);
                        res = n;
                        for(i = 0; i < m; i++)
                        {
                                    scanf("%d%d", &x, &y);
                                    union_set(x, y);
                                }
                        printf("Case %d: %d\n", j, res);
                        j++;
                    }
    return 0;
}
