#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
    int n, i, j, sqrtn, sum = 0;
    cout << "PERFECTION OUTPUT" << endl;
    while(cin >> n && n)
    {
        n != 1 ? sum = 1: sum = 0;
		sqrtn = (int)sqrt((double)n);
        for(i = 2; i <= sqrtn; i++)
        {
	        if(n % i == 0)
				sum += i + n/i;				
        }
        
		printf("%5d  ", n);
        if(sum == n)  
            cout << "PERFECT" << endl;
        else if(sum > n)
            cout << "ABUNDANT" << endl;
        else         
            cout << "DEFICIENT" << endl;
    }                
    cout << "END OF OUTPUT" << endl;

    return 0;
}
