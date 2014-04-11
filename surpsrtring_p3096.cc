#include <iostream>
#include <memory.h>
#include <string>
using namespace std;

int hash(char a, char b)
{
    return (a - 'A')*27 + (b - 'A');
}

bool judge(string str)
{
    int len = str.length();
    int t[800];
    for(int j = 1; j < len - 1; j++)
    {
        memset(t, 0, sizeof(t));
        for(int i = 0; i + j < len; i++)
        {
           int k = hash(str[i], str[i + j]);
           if(t[k] != 0)
               return false;
           else
               t[k] = 1;
        }
    }
    return true;
}

int main()
{
    string str;
    while(cin >> str && str != "*")
    {
        string res = judge(str) ? "surprising." : "NOT surprising."; 
        cout << str << " is " << res << endl;
    }
    return 0;
}
