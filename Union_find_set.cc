#include <iostream>
using namespace std;
const int MAXN = 100;
int parent[MAXN];
int ranks[MAXN];

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
    int t;
    cin >> t;
    while( t-- )
    {

    }
    return 0;
}
