#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
int dp[12900];
int w[3420],v[3420];
int main()
{
    int n,weight;
    int i;
    while(~scanf("%d%d",&n,&weight))
    {
        for(i = 1;i <= n; i++)
          scanf("%d%d", &w[i], &v[i]);
        for(i = 1; i <= n; i++)
        {
            for(int k = weight; k >= w[i]; k--)
            {
                //cout << "->dp[k]:" << dp[k] <<" k:" << k <<" dp[k - w[i]]:" << dp[k - w[i]] << " v[i]:" << v[i]<<  endl;
                dp[k] = max(dp[k], v[i] + dp[k-w[i]]);
                //cout<<"i="<<i<<"  dp["<<k<<"]="<<dp[k]<<endl;
            }
        }
        printf("%d\n",dp[weight]);
    }
}
