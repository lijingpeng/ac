#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, k;
    while(cin >> n >> k && n && k)
    {
        for(int i = 0; i < k; i++)
        {
           int s, t, r;
           cin >> s >> t >> r;
           int c = ceil( float(n) / s );
           cout << c + (ceil(float(c)/t) - 1 ) * r << endl;
        }
    }
    return 0;
}
