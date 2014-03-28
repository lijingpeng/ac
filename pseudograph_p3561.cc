#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    int r, c;
    char map[105][105];
    cin >> n;
    while(n--)
    {
        memset(map, '.', sizeof(map));
        cin >> r >> c;
        int line = 0;
        for(int i = 1; i <= r; i++)
        {
            for(int j = 1; j <= c; j++)
            {
                cin >> map[i][j];
                if(map[i][j] == '.')
                    continue;
                if( map[i][j] == '\\' )
                {
                    if(map[i-1][j-1] == '\\' || map[i+1][j+1] == '\\')
                        continue;
                    else
                        ++line;
                }
                else if( map[i][j] == '/' )
                {
                    if(map[i+1][j-1] == '/' || map[i-1][j+1] == '/')
                        continue;
                    else
                        ++line;
                }
                else if( map[i][j] == '-')
                {
                    if(map[i][j-1] == '-' || map[i][j+1] == '-')
                        continue;
                    else
                        ++line;
                }
                else if( map[i][j] == '|' )
                {
                    if(map[i+1][j] == '|' || map[i-1][j] == '|')
                        continue;
                    else
                        ++line;
                }
             }
        }
        if(line == 1)
            cout << "CORRECT" << endl;
        else
            cout << "INCORRECT" << endl;

    }
    return 0;
}
