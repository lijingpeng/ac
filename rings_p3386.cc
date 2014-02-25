#include <iostream>
using namespace std;

int main()
{
    int A, a, B, b, P;
    while(cin >> A >> a >> B >> b >> P && A)
    {
        if( (A+B <= P) || (B<=a && A<=P) || (A<=b && B<=P) )
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
