#include <iostream>
#include <algorithm>
#include <memory.h> 
#include <cstdio>
using namespace std;
const int MAX = 20002;
long long minCount[MAX];
long long dist[MAX];

typedef struct node{
    int v;
    int x;
}Node;

bool compare(const Node& a, const Node& b)
{
    if(a.v == b.v)
        return a.x < b.x;
    return a.v < b.v;
}

int lowbit(int x){
    return x & -x;
}

long long sum(long long *C, int x) {
    long long sum = 0;
    while(x) {
        sum += C[x];
        x -= lowbit(x);
    }
    return sum;
}

void update(long long *C, int x, int val) {
    while(x < MAX) {
        C[x] += val;
        x += lowbit(x);
    }
}


int main()
{
    int n;
    long long res = 0, cnt, sumi, allx;
    Node cows[MAX];
    while(cin >> n && n)
    {
        memset(minCount, 0, sizeof(minCount));
        memset(dist, 0, sizeof(dist));
        for(int i = 0; i < n; ++i)
            scanf("%d%d", &cows[i].v, &cows[i].x);
        sort(cows, cows + n, compare);

        update(minCount, cows[0].x, 1);
        update(dist, cows[0].x, cows[0].x);
        allx = cows[0].x;
        for(int i = 1; i < n; ++i)
        {
           cnt = sum(minCount, cows[i].x);
           sumi= sum(dist, cows[i].x); 
           //total - sum -（i - cnt)*node.x + node.x*cnt - sum;
           res += cows[i].v * ( allx - (sumi << 1) + cows[i].x * ( (cnt << 1) - i ) );

           update(minCount, cows[i].x, 1);
           update(dist, cows[i].x, cows[i].x);
           allx += cows[i].x;
        }
        cout << res << endl;
    }
    return 0;
}
