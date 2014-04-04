#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

int main()
{
    int n, sets[100005], news[100005];
    while(cin >> n && n)
    {
        int flag = 0;
        memset(sets, 0, sizeof(sets));
        memset(news, 0, sizeof(news));
        for(int i = 1; i <= n; i++)
        {
           scanf("%d", &sets[i]);
        }
        
        for(int j = 1; j <= n; j++)
            news[ sets[j] ] = j;

        for(int i = 1;i <= n; i++)
            if(news[i] != sets[i])
            {
                flag = 1;
                break;
            }

        if(flag)
            cout << "not ambiguous" << endl;
        else
            cout << "ambiguous" << endl;

    }
    return 0;
}
