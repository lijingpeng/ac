#include<iostream>
#include<cstdio>
using namespace std;

int a[] = {1,3,5,4,6};
char str[] = "abcde";

void print_subset(int n , int s)
{
	printf("{");
	for(int i = 0 ; i < n ; ++i)
	{
		if( s&(1<<i) )         // 判断s的二进制中哪些位为1，即代表取某一位
			printf("%c ",str[i]);   //或者a[i]
	}
	printf("}\n");
}

void subset(int n)
{
    int s = 1 << n;
	for(int i= 0 ; i < s ; ++i)
	{
		print_subset(n,i);
	}
}



int main(void)
{
	subset(5);
	return 0;
}
