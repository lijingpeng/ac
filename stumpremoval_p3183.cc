#include <iostream>
using namespace std;

int main()
{
    int n, s[50001];
    while(cin >> n && n)
    {
        for(int i = 0; i < n; i++)
        {
           cin >> s[i]; 
        }
        int pl = 0, pr = 0;
        for(int i = 0; i < n; i++)
        {
            i > 0 ? pl = s[i - 1] : s[i];
            i < n - 1 ? pr = s[i + 1] : s[i];
            if( s[i] >= pl && s[i] >= pr)
            {
                    cout << i + 1 << endl;
            }
        }
    }
    return 0;
}
