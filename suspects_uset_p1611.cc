#include <iostream>
using namespace std;
const int MAXN = 30001;
int parent[MAXN];
int ranks[MAXN];
int num[MAXN];

void make_set(int x)
{
    parent[x] = x;
    ranks[x]  = 0;
    num[x] = 1;
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
    if(ranks[x] > ranks[y])
    {
        parent[y] = x;
        num[x] += num[y];
    }
    else
    {
        parent[x] = y;
        if(ranks[x] == ranks[y])
            ranks[y]++;
        num[y] += num[x];
    }
}

int main()
{
    int n, m, k, x, y;
    while(cin >> n >> m && n != 0)
    {
        if(m == 0)
        {
            cout << "1" << endl;
            continue;
        }
        for(int i = 0; i < n; ++i)
        {
            make_set(i);
        }
        for(int i = 0; i < m; ++i)
        {
            cin >> k >> x;
            for(int j = 1; j < k; ++j)
            {
                cin >> y;
                union_set(x, y);
                x = y;
            }
        }

        cout << num[ find_set(0) ] << endl;
    }
    return 0;
}
