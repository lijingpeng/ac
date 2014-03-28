#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string str, sub;
    while(cin >> n && n)
    {
        for(int i = 0; i < n; i++)
        {
           cin >> str >> sub;
           int k = 0;
           for(int j = 0; j < str.length(); j++)
           {
               if(k < sub.length() && str[j] == sub[k])
                   k++;
           }
           if(k == sub.length())
               cout << "YES" << endl;
           else
           {
               k = 0;
               for(int j = str.length() - 1; j >=0 ; j--)
               {
                   if(k < sub.length() && str[j] == sub[k])
                       k++;
               }
               if( k == sub.length())
                   cout << "YES" << endl;
               else
                   cout << "NO" << endl;
           }
        }
    }
    return 0;
}
