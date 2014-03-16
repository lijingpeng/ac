#include <iostream>
#include<algorithm>
using namespace std;

int comp ( const void *a, const void *b )
{
        return * ( int * ) a - * ( int * ) b;
}

int main()
{
    string a, b;
    int m[26], mi[26], k[26], ki[26];
    cin >> a >> b;
    for(int i = 0; i < 26; i++)
    {
        m[i] = 0;
        k[i] = 0;
    }
    for(int i = 0; i < a.length(); i++)
    {
        m[a[i] - 65]++;
        k[b[i] - 65]++;
    }
    qsort(m, 26, sizeof(int), comp);
    qsort(k, 26, sizeof(int), comp);
    int flag = 0;
    for(int i = 0; i < 26; i++)
        if(m[i] != k[i])
        {
            flag = 1;
            break;
        }
    if(flag)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}
