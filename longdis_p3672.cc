#include <iostream>
using namespace std;

int main()
{
    int m, t, u, f, d, i, sum = 0;
    cin >> m >> t >> u >> f >> d;
    for(i = 0; i < t; i++)
    {
        char s;
        cin >> s;
        if(s == 'u' || s == 'd')
            sum += u + d;
        else
            sum += f + f;
        
        if(sum > m)
            break;
    }
    cout << i << endl;
    return 0;
}
