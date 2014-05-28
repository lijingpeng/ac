#include <iostream>
#include <string>
#include <map>
using namespace std;
const int MAX = 26;
int dict[MAX] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};
int main()
{
    int n;
    while(cin >> n && n)
    {
        map<string, int> numbers;
        string tmp;
        for(int i = 0; i < n; i++)
        {
           cin >> tmp;
           string res = "";
           int valid = 0;
           for(int j = 0; j < tmp.length(); ++j)
           {
               if(tmp[j] >= 'A' && tmp[j] <= 'Z')
               {
                   if(tmp[j] != 'Z' && tmp[j] != 'Q')
                   {
                       res += dict[ tmp[j] - 'A' ] + '0';
                        valid++;
                   }
               }
               else if(tmp[j] >= '0' && tmp[j] <= '9')
               {
                    res += tmp[j];
                    valid++;
               }
               if(valid == 3)
               {
                   res += '-';
                   valid = 999999;
               }
           }
           numbers[res]++;
        }
        map<string, int>::const_iterator itr = numbers.begin();
        int flag = 0;
        for( ; itr != numbers.end(); ++itr)
            if(itr->second > 1)
            {
                cout << itr->first << " " << itr->second << endl;
                flag = 1;
            }
        if(!flag)
            cout << "No duplicates." << endl;
    }
    return 0;
}
