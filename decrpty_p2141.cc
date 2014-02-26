#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    int key[26];
    string keystr;
    cin >> keystr;
    for(int i = 0; i < 26; i++)
    {
        key[i] = keystr[i];
    }
    getchar();
    string msg, res = "";
    getline(cin, msg);
    for(int i = 0; i < msg.length(); i++)
    {
        if(msg[i] != ' ')
        {
            if(msg[i] < 97)
                res += key[ msg[i] - 65] - 32;
            else
                res += key[ (int)msg[i] - 97 ];
        }
        else
        {
            res += " ";
        }
    }
    cout << res << endl;
    return 0;
}
