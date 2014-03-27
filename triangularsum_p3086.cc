#include <iostream>
using namespace std;

int main()
{
    int i, n, m;
    while(cin >> n && n)
    {
        for(i = 0; i < n; i++)
        {
           cin >> m;
           int sum = 1, all = 0;
           for(int j = 1; j <= m; j++)
           {
               sum += j + 1;
               all += j * sum;
           }
           cout << i + 1 << " " << m << " " << all << endl;
        }
    }
    return 0;
}
