#include<stdio.h>
using namespace std;
int main()
{
      int sum,dif,t;
      scanf("%d",&t);
      while(t--)
      {
            scanf("%d %d",&sum,&dif);
            if((sum+dif)%2==1||dif>sum)
                  printf("impossible\n");
            else
                  printf("%d %d\n",(sum+dif)/2,(sum-dif)/2);
      }
      return 0;
}
