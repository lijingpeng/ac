#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n && n)
    {
        int min = 2000, max = 0, t, sum = 0;
        for(int i = 0; i < n; i++)
        {
           cin >> t;
           if(t > max)
               max = t;
           if(t < min)
               min = t;
           sum += t;
        }
        cout << (sum - min - max) / (n - 2) << endl;
    }
    return 0;
}
