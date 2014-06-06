/* 
问题描述:计算n个矩阵连乘所需的最少乘法次数 
*/  
  
#include <iostream>  
#include <string>  
using namespace std;  
  
int Matrix_chain_Multiply(int p[],int n,int m[][8],int s[][8])  
{  
    //这里的n是数组p[]的元素个数，比矩阵个数多了一个  
    n-=1;  
    int i,j,r,k,q;  
  
    for(i=1;i<=n;i++)  
        m[i][i]=0;  //单个矩阵相乘次数为0  
  
    for(r=2;r<=n;r++)   //r为连乘矩阵的个数  
    {  
        for(i=1;i<=n-r+1;i++)   //i就是连续r个矩阵的第一个  
        {  
            j=i+r-1;  //j就是连续r个矩阵的最后一个  
            m[i][j]=99999999;  
            for(k=i;k<j;k++)   //求m[i][j],m[i][j]就是Ai...Aj这 j-i+1 个矩阵连乘需要的最少的乘法次数  
            {  
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];  
                if(q<m[i][j])  
                {  
                    m[i][j]=q;  
                    s[i][j]=k;   //在k处分开是最好的  
                }  
            }  
        }  
    }  
    return m[1][n];   //n个矩阵连乘的最少相乘次数  
}  
  
void Print_Matrix_Chain(string A[],int s[][8],int i,int j)  
{  
    //输出最优解  
    if(i == j)  
        cout<<A[i-1]<<" ";  
    else  
    {  
        cout<<"( ";  
        Print_Matrix_Chain(A,s,i,s[i][j]);  
        Print_Matrix_Chain(A,s,s[i][j]+1,j);  
        cout<<") ";  
    }  
}  
  
int main()  
{  
    int p[7]={30,35,15,5,10,20,25};  
    int m[8][8],s[8][8];  
    int min=Matrix_chain_Multiply(p,7,m,s);  
    cout<<"上述6个矩阵连乘，最少需要做 "<<min<<" 次乘法运算"<<endl;  
    string A[6]={"A1","A2","A3","A4","A5","A6"};  
    cout<<"最优的全加括号形式为：";  
    Print_Matrix_Chain(A,s,1,6);  
    cout<<endl;  
    return 0;  
}  
