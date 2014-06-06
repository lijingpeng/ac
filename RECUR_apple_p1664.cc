#include <iostream>
using namespace std;

int place(int m, int n)
{
    if(n == 1 || m == 0)
        return 1;
    if(m < 0)
        return 0;
    return place(m - n, n) + place(m, n - 1);
}

int main()
{
    int t, m, n;
    cin >> t;
    while( t-- )
    {
        cin >> m >> n;
        cout << place(m, n) << endl;
    }
    return 0;
}
