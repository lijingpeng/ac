#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, c = 0;
    string strs[15];
    while(cin >> n && n)
    {
        cout << "SET " << ++c << endl;
        for(int i = 0; i < n; i++)
        {
           cin >> strs[i];
        }
        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 0)
                cout << strs[i] << endl;
        }
        for(int i = n - 1; i >= 0; i--)
        {
            if(i % 2 != 0)
                cout << strs[i] << endl;
        }
    }
    return 0;
}
