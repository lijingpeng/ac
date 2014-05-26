#include<stdio.h>
int main()
{
      int t,a,p;
      scanf("%d", &t);
      while(t--)
      {
            scanf("%d",&a);
            for(p=2;a%p==0;p*=2)
                ;
            
            p = p/2 - 1;
            printf("%d %d\n", a - p,a + p);
      }
   return 0;  
}
