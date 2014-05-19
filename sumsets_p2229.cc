#include <iostream>
using namespace std;
const int M = 1000000000;
int main()
{
    int n;
    int s[1000001];
    while(cin >> n && n)
    {
        s[0] = s[1] = 1;
        for(int i = 2; i <= n; i++)
        {
           if(i & 1) 
               s[i] = s[i - 1];
           else
               s[i] = (s[i - 2] + s[ i >> 1 ]) % M;
        }
        cout << s[n] << endl;
    }
    return 0;
}
