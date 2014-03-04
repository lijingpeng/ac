#include <iostream>
using namespace std;

int main()
{
    int c, f1, f2, d, cow[101][2];
    cin >> c >> f1 >> f2 >> d;
    for(int i = 0; i < c; i++)
    {
        // cows
        cin >> cow[i][0] >> cow[i][1];
    }

    int feed = 0, i;
    for(i = d; f1 - feed != f2 ; i--)
    {
        for(int j = 0; j < c; j++)
        {
            if(cow[j][0] <= i && cow[j][1] >= i)
                feed++;
        }
    }
    
    cout << i + 1 << endl;
    return 0;
}
