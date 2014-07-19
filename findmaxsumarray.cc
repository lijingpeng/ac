#include <stdio.h>
#include <string.h>
const int MAX = 110;

int FindMaxSubArray(const int *temp, int n)
{
    int i,sum=0,max=0;
    for(i=0;i<n;i++)
    {
        sum+=temp[i];
        if(sum<0)sum=0;
        if(sum>max)max=sum;
    }
    return max;
}

//n 行， m列
int FindMaxSubArray2(const int a[][MAX], int n, int m)
{
    int max=-9999;
    int temp[MAX];
    for(int i=0;i<n;i++)
    {
        memset(temp,0,sizeof(temp));
        for(int j=i;j<n;j++)   //j表示行
        {
            for(int k=0;k<m;k++)   //k表示列
            {
                temp[k]+=a[j][k];
            }
            int res = FindMaxSubArray(temp, n);
            if(max < res)
                max = res;
        }
    }
    return max;
}

int main()
{
    int N;
    while(~scanf("%d",&N))
    {
        int map[MAX][MAX];
        for(int i = 0;i < N;i ++)
            for(int j = 0;j < N;j ++)
                scanf("%d",&map[i][j]);

        printf("%d\n", FindMaxSubArray2(map, N, N));
    }
}
