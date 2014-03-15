#include <iostream>
using namespace std;

int main()
{
    int n;
    char mx[200][20];
    string str;
    while(cin >> n && n)
    {
        cin >> str;
        for(int i = 0; i < str.length();)
        {
            for(int j = 0; j < str.length() / n; j++)
            {
                if(j % 2 == 0)
                    for(int k = 0; k < n; k++)
                        mx[j][k] = str[i++];
                else
                    for(int k = n - 1; k >= 0; k--)
                        mx[j][k] = str[i++];
            }
        }

        string res("");
        for(int j = 0; j < n; j++)
            for(int i = 0; i < str.length() / n; i++)
                res += mx[i][j];

        cout << res << endl;
    }
    return 0;
}
