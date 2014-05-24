#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n && n)
    {
        char ch;
        int c = 0, s = 0, f = 0;
        for(int i = 0; i < n; i++)
        {
           cin >> ch; 
           if(ch == 'C')
               ++c;
           else if(ch == 'S')
               ++s;
           else
               ++f;
        }
        int res = 0;
        if(c == n || s == n || f == n)
            res = n;
        else if(c != 0 && s != 0 && f != 0)
            res = n;
        else
        {
            if(c == 0)
                res = s;
            else if(s == 0)
                res = f;
            else if(f == 0)
                res = c;
        }
        cout << res << endl;
    }
    return 0;
}
