#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    long fact = 0, prevf = 2;
    int i = 0, n =0;
    double newe = 1, e = 2.5;
    cout << "n e" << endl;
    cout << "- -----------" << endl;
    cout << "0 1" << endl;
    cout << "1 2" << endl;
	cout << "2 2.5" << endl;
    for(n = 3; n < 10; n++)
    {
        fact = prevf * n;
        newe = 1 / (double)fact;
        e += newe;
        prevf = fact;
        
        printf("%d %.10g\n", n, e);
    }
}
