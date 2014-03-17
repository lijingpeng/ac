#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char a[10], b[10];
    while(cin >> a >> b && (a[0] - '0' || b[0] - '0'))
    {
        int cnt = 0, c = 0;
        for(int i = strlen(a) - 1, j = strlen(b) - 1; i >= 0 || j >= 0; i--, j--)
        {
            int at = i >= 0 ? a[i] - 48 : 0;
            int bt = j >= 0 ? b[j] - 48 : 0;
            int t = at + bt + c; 
            if(t > 9)
            {
                c = t / 10;
                cnt++;
            }
            else
                c = 0;
        }
        if(cnt == 0)
            cout << "No carry operation." << endl;
        else if(cnt == 1)
            cout << "1 carry operation." << endl;
        else
            cout << cnt << " carry operations." << endl;
    }
    return 0;
}
