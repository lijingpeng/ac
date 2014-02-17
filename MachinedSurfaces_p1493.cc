#include <iostream>
using namespace std;
const int MAX = 14;
int main()
{
    int n, xsum[MAX], xmax = 0;
    while(cin >> n && n != 0)
    {
    for(int i = 0; i < n; i++)
    {
        cin.get();
        char s[26];
        cin.getline(s, 25);    
        int cnt = 0;
        for(int j = 0; j < 25; j++)
        {
            if(s[j] == 'X')
                cnt++;
        }
        xsum[i] = cnt;
        if(cnt > xmax)
            xmax = cnt;
    }
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += (xmax - xsum[i]);

    cout << sum << endl;
    }
    return 0;
}
