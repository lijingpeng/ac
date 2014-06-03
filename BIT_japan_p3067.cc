#include <iostream>
#include <algorithm>
#include <memory.h> 
#include <cstdio>
using namespace std;
const int MAX = 1005;
int mini[MAX];
typedef struct point
{
    int s;
    int e;
}Point;

bool compare(const Point& a, const Point& b)
{
    if(a.s == b.s)
        return a.e < b.e;
    return a.s < b.s;
}

int lowbit(int x)
{
    return x & -x;
}

long long sum(int x)
{
    long long sum = 0;
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
    int n, t = 0;
    Point val[MAX*MAX];
    cin >> n;
    while(n--)
    {
        int m, p, k;
        cin >> m >> p >> k;
        memset(mini, 0, sizeof(mini));
        long long res = 0;
        for(int i = 0; i < k; i++)
        {
            scanf("%d%d", &val[i].s, &val[i].e);
        }
        sort(val, val+k, compare);

        for(int i = 0; i < k; i++)
        {
            res += ( i - sum(val[i].e) );      
            update(val[i].e, 1);     
        }
        cout << "Test case " << ++t << ": " << res << endl;
    }
    return 0;
}
