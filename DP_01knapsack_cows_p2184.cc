#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
const int INF = 999999999;
const int MAX = 200009;
const int DELTA = 10000;
const int MAXN  = 110;
int dp[MAX];
int main()
{
    int n, ts[MAXN], tf[MAXN], i, j;
    while(scanf("%d", &n) != EOF)
    {
       for(i = 0; i < MAX; ++i)
           dp[i] = -INF;
       dp[DELTA] = 0;
       for(i = 1; i <= n; ++i)
           scanf("%d%d", &ts[i], &tf[i]);

       for(i = 1; i <= n; ++i)
       {
           if(ts[i] > 0)
           {
               for(j = MAX; j >= ts[i]; --j)
               {
                   dp[j] = max(dp[j - ts[i]] + tf[i], dp[j]);
               }
           }
           else
           {
               for(j = 0; j < MAX + ts[i]; ++j)
               {
                   dp[j] = max(dp[j - ts[i]] + tf[i], dp[j]);
               }
           }
       }

       int res = 0;
       for(i = DELTA; i < MAX; ++i)
       {
           if(dp[i] > 0 && (i - DELTA + dp[i] > res))
               res = i - DELTA + dp[i];
       }
       printf("%d\n", res);
    }
}
