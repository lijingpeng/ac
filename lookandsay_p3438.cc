#include <iostream>
using namespace std;

int main()
{
    int n;
    string str;
    while(cin >> n && n)
    {
        for(int i = 0; i < n; i++)
        {
           cin >> str;
           int cnt = 1;
           int len = str.length();
           for(int j = 1; j <= len; j++)
           {
               if(j < len && str[j] == str[j - 1])
               {
                   cnt++;
               }
               else
               {
                   cout << cnt << str[j - 1];
                   cnt = 1;
               }
           }
           cout << endl;
        }
    }
    return 0;
}
