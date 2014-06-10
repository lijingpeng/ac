#include<iostream>
#include<stdio.h>
#include<cmath>
#include<memory.h>
#include<algorithm>
using namespace std;
const int MAX = 1000005;
int dp[MAX];
int cow[22];
int main()
{
    int n, height;
    int i;
    while(~scanf("%d%d",&n,&height))
    {
        int sum = 0;
        memset(dp, 0, sizeof(dp));
        for(i = 1;i <= n; i++)
        {
            scanf("%d", &cow[i]);
            sum += cow[i];
        }

        for(i = 1; i <= n; i++)
        {
            for(int k = sum; k >= cow[i]; k--)
            {
                dp[k] = max(dp[k], cow[i] + dp[k-cow[i]]);
            }
        }

        for(i = 0; i <= sum; i++)
            if(dp[i] >= height)
            {
                cout << dp[i] - height << endl;
                break;
            }
    }
}
