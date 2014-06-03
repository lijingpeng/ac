#include <iostream>
#include <algorithm>
#include <memory.h> 
#include <cstdio>
using namespace std;
const int MAX = 100001;
int mini[MAX];
typedef struct point
{
    int s;
    int e;
    int id;
}Point;

bool compare(const Point& a, const Point& b)
{
    if(a.e == b.e)
        return a.s < b.s;
    return a.e > b.e;
}

int lowbit(int x)
{
    return x & -x;
}

int sum(int x)
{
    int sum = 0;
    while(x)
    {
        sum += mini[x];
        x -= lowbit(x);
    }
    return sum;
}

void update(int x, int val)
{
    while(x < MAX)
    {
        mini[x] += val;
        x += lowbit(x);
    }
}

int main()
{
    int n;
    Point val[MAX];
    int cnt[MAX];
    while(cin >> n && n)
    {
        memset(mini, 0, sizeof(mini));
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &val[i].s, &val[i].e);
            val[i].s++;
            val[i].e++;
            val[i].id = i;
        }
        sort(val, val+n, compare);

        cnt[val[0].id] = sum(val[0].s);
        update(val[0].s, 1); 
        for(int i = 1; i < n; i++)
        {
            if(val[i - 1].s == val[i].s && val[i - 1].e == val[i].e)
                cnt[ val[i].id ] = cnt[ val[i - 1].id ];
            else
                cnt[ val[i].id ] = sum(val[i].s);

            update(val[i].s, 1);     
        }
        for(int i = 0; i < n - 1; ++i)
            printf("%d ", cnt[i]);
        printf("%d\n", cnt[n - 1]); 
    }
    return 0;
}
