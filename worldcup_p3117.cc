#include <iostream>
#include <string>
using namespace std;

int main()
{
    int team, m;
    while(cin >> team >> m)
    {
        if(team == 0 && m == 0)
            break;
        int sum = 0, a;
        string str;
        for(int i = 0; i < team; i++)
        {
           cin >> str >> a;
           sum += a;
        }
        cout << m*3 - sum << endl;
    }
    return 0;
}
