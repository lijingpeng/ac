#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, ints[3001], t, diff[3001];
     while(cin >> n && n)
    {
        for(int i = 0; i < 3001; i++)
        {
            ints[i] = 0;
            diff[i] = 0;
        }

/*        if(n == 1)
        {
            cin >> t;
            cout << "Jolly" << endl;
            continue;
        }
*/
        t = 1;
        for(int i = 0; i < n; i++)
        {
            cin >> ints[i];
            if(i)
            {
                int idiff = fabs(ints[i] - ints[i - 1]);
                if(!diff[ idiff ])
                    diff[idiff] = 1; 
                else
                    t = 0;
            }
        }

        for(int i = 1; t && i < n; i++)
            {
                if(diff[i] == 0)
                {
                    t = 0;
                    break;
                }
            }

        if(t == 1)
            cout << "Jolly" << endl;
        else
            cout << "Not jolly" << endl;
    }
    return 0;
}
