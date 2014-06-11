#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int t,n,m,a[1100];
	scanf("%d",&t);
	while(t--)
	{
		int i;
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		for(i=0;i<m;i++) next_permutation(a,a+n);
		for(i=0;i<n;i++) printf("%d ",a[i]);
		puts("");
	}
	return 0;
}
