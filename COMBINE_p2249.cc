//2249 not submit
/*求组合数 CM取N。。
原来这就是传说中的组合数学
先求AM取N 再除N阶乘的话 肯定越界
乘一个数 然后马上除一个数  可以保证数字一直比结果小 递增到结果
但是这样又遇到浮点数除法问题 不过这道题里用double就可以解决精度问题*/

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int m,n;
	while (cin>>m>>n&&m!=0)
	{
		double result = 1;
		if(n>m/2)
			n=m-n;
		if(n==0)
		{
			cout<<"1"<<endl;
			continue;
		}
		for (int i = 0;i < n;i++)
		{
			result*=(m-i);
			result/=(n-i);
		}
		printf("%.0lf\n",result);
	}
}
