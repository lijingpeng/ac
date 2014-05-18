#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int n;
    while((scanf("%d",&n)!=EOF)&&(n!=0))
    {
        int i;
        double s,t,tmp,times;
        times=999999.0;
        for(i=1;i<=n;i++)
        {
            scanf("%lf%lf",&s,&t);
            if(t<0)
            {
                continue;
            }
            tmp=ceil((4.5*3600)/s+t);
            if(tmp<times)
            {
                times=tmp;
            }
        }
        printf("%d\n",(int)times);
    }
    return (0);
}
