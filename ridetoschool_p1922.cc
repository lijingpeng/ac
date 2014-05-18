#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    while(cin >> n && n)
    {
        float speed, times, cost, max = 9999999;
        for(int i = 0; i < n; i++)
        {
            cin >> speed >> times;
            if(times < 0)
                continue;

            cost = ceil( 4500*3.6 / speed + times );
            max = max > cost ? cost : max;
        }
        cout << (int)(max) << endl;
    }
    return 0;
}
