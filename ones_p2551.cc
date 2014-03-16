#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int k;
    while(scanf("%d",&k)!=EOF)
    {//模拟除法 余数+1 而非+0

        int n=1,cnt=1;
        while(n!=0)
        {
            while(n<k) n=n*10+1,cnt++;//到最小的11...
            n=n%k; //取余
        }
        printf("%d\n",cnt);

    }
}
