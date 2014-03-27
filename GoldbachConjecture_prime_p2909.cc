#include <iostream>
#include <cmath>
using namespace std;

int isPrime(int a)
{
    double da = sqrt( double(a) );
    for(int i = 2; i <= da; i++)
    {
        if(a % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int n;
    while(cin >> n && n)
    {
        int flag = 0, sum = 0;
        for(int i = 3; i <= n / 2; i += 2)
        {
           if( isPrime(i) && isPrime(n-i) )
           {
               sum++;
           }
        }
        cout << sum << endl;
    }
    return 0;
}
