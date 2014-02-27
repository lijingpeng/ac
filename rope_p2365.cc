#include <cstdio>
#include <cmath>
#define PI 3.141592653589
int main()
{
	double N;
    double radius;
	while(scanf("%lf%lf",&N,&radius)!=EOF)
	{
		double x,y,topx,topy;
		scanf("%lf%lf",&topx,&topy);
		x=topx,y=topy;
		double ans=2*PI*radius;
		for (int i=1;i<N;++i)
		{
			double a,b;
			scanf("%lf%lf",&a,&b);
			ans+=sqrt((a-x)*(a-x)+(b-y)*(b-y));
			x=a,y=b;
		}
		ans+=sqrt((x-topx)*(x-topx)+(y-topy)*(y-topy));
		printf("%.2lf\n",ans);
	}
	return 0;
}
