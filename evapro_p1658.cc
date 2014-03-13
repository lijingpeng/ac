#include <iostream>
using namespace std;

int main()
{
    int n, a[4], flag = 1;
    while(cin >> n && n)
    {
        for(int i = 0; i < n; i++)
        {
           for(int j = 0; j < 4; j++)
           {
                cin >> a[j];
           }

           if(a[3] - a[2] == a[2] - a[1])
           {
               flag = 1;
           }
           else
               flag = 0;

           for(int j = 0; j < 4; j++)
               cout << a[j] << " ";
           if(flag)
               cout << a[3] + a[3] - a[2] << endl;
           else
               cout << a[3] * (a[3]/a[2]) << endl;
        }
    }
    return 0;
}
