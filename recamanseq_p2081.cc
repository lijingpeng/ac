#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n && n != -1)
    {
        bool a[500000*10];
        int t, pt = 0;
        for(int i = 0; i < 500000*10; i++) a[i] = false;
        for(int i = 1; i <= n; i++)
        {
            t = pt - i;
            if(t > 0 && !a[t])
            {
                a[t] = true;
            }
            else
            {
                t = pt + i;
                a[t] = true;
            }

            pt = t;
        }
        cout << t << endl;
    }
    return 0;
}
