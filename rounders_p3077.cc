#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
double tmp,input,ans;
int main()
{
	int n;
	char a[100];
	scanf("%d",&n);
	while(n--){

		scanf("%s",&a);

		for (int i=strlen(a) - 2;i>=0;--i)
			if (a[i+1] >= '5')
			{
				a[i+1] = '0';
				a[i] ++;
			}
			else
				a[i+1] = '0';
		if (a[0] > '9')
		{
			a[0] = '0';
			printf("1");
		}
		printf("%s\n",a);
	}
}

