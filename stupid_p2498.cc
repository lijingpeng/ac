#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, factor[] = {9, 3, 7};
    string str;
    while(cin >> n && n)
    {
        for(int i = 0; i < n; i++)
        {
           cin >> str;
           int k = 0, sum = 0, index, fa;
           for(int j = str.length() - 1; j >= 0; j--)
           {
               if(str[j] != '?')
                   sum += (str[j] - '0') * factor[k++ % 3];
               else
               {
                   index = j;
                   fa = factor[k++ % 3];
               }
           }
            
           for(int j = 0; j < 10; j++)
           {
               if( (sum+j*fa) % 10 == 0 )
               {
                   cout << "Scenario #" << i + 1 << ":" << endl;
                   cout << str.replace(index, 1, 1, char(48+j)) << endl << endl;
                   break;
               }
           }

        }
    }
    return 0;
}
