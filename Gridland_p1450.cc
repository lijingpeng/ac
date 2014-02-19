#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main()
{
    int sec, cnt = 0, m, n;
    cin >> sec;
    while( sec-- )
    {
        cin >> m >> n;
		double res = 0.0;
        if(m%2 && n%2)
        {
			res = m * n - 1 + sqrt(2.0);
        }
        else
			res = m*n;
        
		cout << "Scenario #" << ++cnt <<":" << endl;
		printf("%.2f\n\n", res);
    }
    return 0;
}
