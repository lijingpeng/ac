#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, e, sum = 0, s;
    while(cin >> n >> e && n)
    {
        sum = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> s;
            int p = pow(s, e);
            if(p > 0)
                sum += p;
        }
        cout << sum << endl;
    }
    return 0;
}
