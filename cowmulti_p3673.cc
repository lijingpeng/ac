#include<stdio.h>
#include<string.h>
main()
{
	char a[10],b[10];
	int i,m,n,j;
	long sum=0;
	scanf("%s %s",a,b);
	m=strlen(a);
	n=strlen(b);
	for(i=0;i<m;i++) a[i]=a[i]-'0';
    for(i=0;i<n;i++) b[i]=b[i]-'0';
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			sum=sum+a[i]*b[j];
		}

	}
	printf("%ld\n",sum);

}
