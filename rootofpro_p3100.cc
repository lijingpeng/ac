#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int b, n, i = 1;
    while(cin >> b >> n && n && b)
    {
        int apow = pow(1, n);
        int diff = fabs(b - apow);

        i = 1;
        int prevdiff = 0;
        do
        {
            prevdiff = diff;
            apow = pow(++i, n);
            diff = fabs(b - apow);
        }while(diff < prevdiff);
        cout << i - 1 << endl;
    }
    return 0;
}
