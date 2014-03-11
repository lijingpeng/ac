#include<iostream>
#include<fstream>
using namespace std;
 
 
long long a[1501];
 
void read(){
//  ifstream cin("in.txt");
    int i,j,k;
    int a1=1,a2=1,a3=1;
    a[1]=1;
    a1=1;
    a2=1;
    a3=1;
 
    for(i=2;i<=1500;i++)
    {
        a[i]=min(a[a1]*2,min(a[a2]*3,a[a3]*5));
        if(a[i]==a[a1]*2)
            a1++;
        if(a[i]==a[a2]*3)
            a2++;
        if(a[i]==a[a3]*5)
            a3++;
 
    }
     
    while(1){
        cin>>i;
        if(i==0) return ;
        cout<<a[i]<<endl;
    }
}
 
int main(){
    read();
    return 0;
}
