#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    //freopen("t.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        string x, y;
        cin >> x;
        cin >> y;
        int a = 0, b = 0;
        for (int i = 0; i < 4; i++)
            if (x.find(y[i]) != string::npos)
                b++;
        for (int i = 0; i < 4; i++)
            if (x[i] == y[i])
                a++;
        b-= a;
        printf("%dA%dB\n", a, b);
    }
    return 0;
}
