#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;


bool cmp(char c1,char c2)// 按照'A'<'a'<'.B'<'b'<...<'Z'<'z'排序
{
  if(tolower(c1) == tolower(c2))
return c1 < c2;
else
return tolower(c1) < tolower(c2);
}


int main()
{
    int cas;
    cin>>cas;
    while(cas--)
    {
     string str;
     cin>>str;
     sort(str.begin(),str.end(),cmp);
    do{
        cout << str << endl;
    }while(next_permutation(str.begin(),str.end(),cmp));
    }
    return 0;
}
