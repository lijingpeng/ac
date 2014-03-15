#include <iostream>
#include<algorithm>
using namespace std;

int comp ( const void *a, const void *b )
{
        return * ( int * ) a - * ( int * ) b;
}

int main()
{
    int n, p;
    int hard[101], easy[101], rate[101], b[101];
    while(cin >> n >> p && n && p)
    {
        for(int i = 0; i < 101; i++)
        {
            hard[i] = 0;
            easy[i] = 0;
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < p; j++)
            {
                cin >> rate[j];
                b[j] = rate[j];
            }
            
            qsort(b, p, sizeof(int), comp);
            for(int j = 0; j < p; j++)
            {
                if(rate[j] == b[0])
                    easy[j]++;
                if(rate[j] == b[p - 1])
                    hard[j]++;
            }
        }

        int flag = 0;
        for(int i = 0; i < p; i++)
        {
            if(easy[i] > n / 2 && hard[i] == 0)
            {
                cout << i + 1 << " ";
                flag = 1;
            }
        }
        if(!flag)
            cout << "0";
        cout << endl;
    }
    return 0;
}
