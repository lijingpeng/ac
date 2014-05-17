#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string dict[101], orgin[101], tmp;
    int n = 0;
    while(cin >> tmp && tmp != "XXXXXX")
    {
        dict[n++] = tmp;
    }
    sort(dict, dict + n);
    for(int i = 0; i < n; i++)
    {
        orgin[i] = dict[i];
        sort(dict[i].begin(), dict[i].end());
    }
    while(cin >> tmp && tmp != "XXXXXX")
    {
        int flag = 0;
        sort(tmp.begin(), tmp.end());
        for(int i = 0; i < n; i++)
            if(dict[i] == tmp)
            {
                cout << orgin[i] << endl;
                flag = 1;
            }
        if(!flag)
            cout << "NOT A VALID WORD" << endl;
        cout << "******" << endl;
    }
    return 0;
}
