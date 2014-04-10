#include<iostream>
using namespace std;
int main()
{
 int count[100];
 int list[100][100];
 int temp=0;
 int max=0;
 int n;
 cin>>n;
 for(int i=0;i<n;i++)
 {
  count[i]=0;
  for(int j=0;j<n;j++)
  {
   cin>>list[i][j];
   if(list[i][j]==3)
   count[i]++;
   
  }
  if(max<count[i])
  {
   max=count[i];
   temp=i;   
  }
  
  
 }
 cout<<temp+1<<endl;
 return 0;
 
 
}
