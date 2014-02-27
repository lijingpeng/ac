#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, m, sum, sc[1001], t;
    while(cin >> n && n)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> m;
            sum = 0;
            for(int j = 0; j < m; j++)    
            {
                cin >> sc[j];
                sum += sc[j];
            }

            float avg = sum / (float)m;
            t = 0;
            for(int i = 0; i < m; i++)
            {
                if(sc[i] > avg)
                    t++;
            }
            printf("%.3f%%\n", 100 * t/(float)m);
        }
    }
    return 0;
}
