#include <iostream>
#include <cmath>
using namespace std;

int isPrime(int a)
{
    float r = sqrt(a);
    for(int i = 2; i <= r; i++)
        if( a % i == 0)
            return 0;

    return 1;
}

int main()
{
    int num;
    while(cin >> num && num)
    {
       if( !isPrime(num))
       {
           int left, right;
           for(int j = num + 1; ; j++)
               if(isPrime(j))
               {
                   right = j;
                   break;
               }

           for(int j = num - 1; ; j--)
               if(isPrime(j))
               {
                   left = j;
                   break;
               }

           cout << right - left << endl;

       }
       else
       {
           cout << "0" << endl;
       }
    }
    return 0;
}
