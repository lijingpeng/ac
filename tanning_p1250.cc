#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

int main()
{
    int n, people[26];
    while(cin >> n && n)
    {
        int cnt = 0, away = 0;
        string c;
        memset(people, 0, sizeof(people));
        cin >> c;
        for(int i = 0; i < c.length(); i++)
        {
            if(cnt >= n && people[c[i] - 'A'] == 0)
            {
                away++;
                continue;
            }
            if(people[c[i] - 'A'])
            {
                //people go away;
                people[c[i] - 'A'] = 0;
                cnt--;
            }
            else
            {
               people[c[i] - 'A'] = 1;
               cnt++;
            }
        }
        if(away == 0)
            cout << "All customers tanned successfully." << endl;
        else
            cout << away / 2<< " customer(s) walked away." << endl;
    }
    return 0;
}
