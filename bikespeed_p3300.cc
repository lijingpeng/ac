#include <iostream>
#include <algorithm>
#include <cstdio>
#include <memory.h>
using namespace std;

int main()
{
    int n, m, fr[6], rr[11];
    float dd[61] = {0.0};
    while(cin >> n && n && cin >> m && m)
    {
        memset(dd, 0.0, sizeof(dd));
        for(int i = 0; i < n; i++)
            cin >> fr[i];
        for(int i = 0; i < m; i++)
            cin >> rr[i];

        int k = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                dd[k++] = (float)rr[j] / fr[i];

        sort(dd, dd+k);
        float max = 0;
        for(int i = 0; i < 60; i++)
        {
            float t = dd[i+1] / dd[i];
            if(t > max)
                max = t;
        }

        printf("%.2f\n", max);
    }
    return 0;
}
