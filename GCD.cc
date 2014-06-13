#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    int r = a % b;
    while(r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}
int main()
{
    int t;
    cin >> t;
    while( t-- )
    {

    }
    return 0;
}
