#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    while(cin >> n && n)
    {
        cout << n << " " ;
        double a, b, c, d, x, y;
        cin >> a >> b;
        x = a; y = b;
        for(int i = 0; i < n - 1; i++)
        {
            cin >> c >> d;
            printf("%.6f %.6f ", (double)( (a+c)/2 ), (double)( (b+d)/2));
            a = c; b = d;
        }
        printf("%.6f %.6f\n", (double)( (a+x)/2 ), (double)( (b+y)/2));
    }
    return 0;
}
