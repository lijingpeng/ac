#include <iostream>
using namespace std;

int main()
{
    int n, d;
    while(cin >> n >> d && n && d)
    {
        int a;
        int prev[501];
        for(int i = 0; i< 501; i++)
            prev[i] = 1;
        for(int i = 0; i < d; i++)
            for(int j = 0; j < n; j++)
            {
                cin >> a;
                prev[j] &= a;
            }   

        int flag = 0;
        for(int i = 0; i < n; i++)
            if(prev[i] == 1)
            {
                flag = 1;
                break;
            }

        flag ? cout << "yes" << endl : cout << "no" << endl;
    }
    return 0;
}
