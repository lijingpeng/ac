#include <iostream>
#include <string.h>
using namespace std;
int grid[101][101]={0};///初始化所有grid网格为白色，用0表示

int Calculate(int,int,int);//个人比较喜欢用一个函数来进行运算
int main()
{
	int n,x,y,l,bnum=0;
	char color[10];
    cin>>n;
    while(n--)
    {
    	cin>>color>>x>>y>>l;
    	for(int p=x;p<=x+l-1;p++)
         for(int q=y;q<=y+l-1;q++)
        {
  	  if(!strcmp(color,"WHITE"))
  	  {
  	    grid[p][q]=0;
  	  }
  	  else if(!strcmp(color,"BLACK"))
  	  {
  	    grid[p][q]=1;
  	  }
  	}
          if(!strcmp(color,"TEST"))
  	     {
  	      cout<<Calculate(x,y,l)<<endl;
         } 		   		          	
    }
    return 0;
}

int Calculate(int x,int y,int l)//计算出所有黑网格的数量 
{
	int blackNum=0;
	for(int i=x;i<=x+l-1;i++)
  		   for(int j=y;j<=y+l-1;j++)
  		   {
  		   	if(grid[i][j])
  		   	blackNum++;
  		   }
  		   return blackNum;
}
