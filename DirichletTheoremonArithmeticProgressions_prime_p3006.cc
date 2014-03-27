#include <iostream>
#include <cmath>
using namespace std;
int isPrime(int a)
{
    double s = sqrt(double(a));
    for(int i = 2; i <= s; i++)
    {
        if(a % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int a, d, n;
    while(cin >> a >> d >> n && a && d && n)
    {
        int t = a, pidx = 0, i = 0;
        while( pidx != n)
        {
           if( isPrime(t) && t != 1 )
               pidx++;

           t = t + d;
        }
        cout << t - d << endl;
    }
    return 0;
}
