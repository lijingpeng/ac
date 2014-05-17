#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 3001;

int main()
{
    int n;
    while(cin >> n && n)
    {
        int last[MAX], first[MAX], ones = 0, used[MAX], next[MAX];
        memset(used, false, sizeof(used));
        memset(first, 0, sizeof(first));
        for(int i = 0; i < n; i++)
        {
            cin >> last[i];
            if(last[i] == 1)
                ones++;
        }
        for(int i = n - ones; i < n; ++i)
            first[i] = 1;

        for(int i = 0; i < n; ++i)
        {
            int j = 0;
            while(first[i] != last[j] || used[j])
                ++j;
            used[j] = true;
            next[i] = j;
        }
        int index = 0;
        for(int i = 0; i < n; ++i)
        {
            index = next[index];
            cout << last[index] << " ";
        }
        cout << endl;
    }

    return 0;
}
