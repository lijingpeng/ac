#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int main()
{
    int area, k, min, a, b, c;
    while(cin >> area && area)
    {
        int res = INT_MAX;
        for(int i = 1; i <= sqrt((float)area) + 1; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                if(area % (i * j) == 0)
                {
                    k = area / (i * j);
                    min = i*j*2 + i*k*2 + j*k*2;
                    if(res > min)
                    {
                        res = min;
                        a = i;
                        b = j;
                        c = k;
                    }
                }
            }
        }

        cout << a << " " << b << " " << c << endl;
    }
    return 0;
}
