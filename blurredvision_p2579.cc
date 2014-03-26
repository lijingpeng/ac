#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str[101];
    int r, c;
    while(cin >> str[0] && str[0] != "ENDOFINPUT")
    {
        cin >> r >> c;
        for(int i = 0; i < r; i++)
            cin >> str[i];

        for(int i = 0; i < r - 1; i++)
        {
           for(int j = 0; j < c - 1; j++)
           {
               cout << (str[i][j] + str[i + 1][j] + str[i + 1][j + 1] + str[i][j + 1] -48-48-48-48) / 4;
           }
           cout << endl;
        }
        cin >> str[0];
    }
    return 0;
}
