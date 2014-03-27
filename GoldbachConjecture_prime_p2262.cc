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
        int flag = 0;
        for(int i = 3; i <= n / 2; i += 2)
        {
           if( isPrime(i) && isPrime(n-i) )
           {
               flag = 1;
               cout << n << " = " << i << " + "<< n - i<<endl;
               break;
           }
        }
        if(!flag)
            cout << "Goldbach's conjecture is wrong."<<endl;
    }
    return 0;
}
