#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n && n)
    {
        for(int i = 0; i < n; i++)
        {
            int k, sum = 0;
            cin >> k;
            for(int j = 0; j < k; j++)
            {
                int t;
                cin >> t; 
                sum += t;
            }
            cout << sum - k + 1 << endl;
        }
    }
    return 0;
}
