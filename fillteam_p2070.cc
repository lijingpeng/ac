#include <iostream>
using namespace std;

int main()
{
    double a, b, c;
    int f = 0;
    while(cin >> a >> b >> c && a && b && c)
    {
		f = 0;
        if(a <= 4.5 && b >= 150 && c >= 200)
            {cout << "Wide Receiver "; f = 1;}
        if(a <= 6.0 && b >= 300 && c >= 500)
            {cout << "Lineman "; f = 1;}
        if(a <= 5.0 && b >= 200 && c >= 300)
            {cout << "Quarterback "; f = 1;}
        if(!f)
            cout << "No positions";
        cout << endl;
    }
    return 0;
}
