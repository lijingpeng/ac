#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n && n)
    {
        for(int i = 0; i < n; i++)
        {
            int m, a, max = 0, min = 99999999;
            cin >> m;
            for(int j = 0; j < m; j++)
            {
                cin >> a;
                if(a > max)
                    max = a;
                if(a < min)
                    min = a;
            }
            cout << 2*(max - min) << endl;
        }
    }
    return 0;
}
