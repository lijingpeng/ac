#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    while(getline(cin, str) && str != "#")
    {
        string res = "";
        for(int i = 0; i < str.length(); i++)
        {
           if(str[i] == ' ')
               res += "%20";
           else if(str[i] == '!')
               res += "%21";
           else if(str[i] == '$')
               res += "%24";
           else if(str[i] == '%')
               res += "%25";
           else if(str[i] == '(')
               res += "%28";
           else if(str[i] == ')')
               res += "%29";
           else if(str[i] == '*')
               res += "%2a";
           else
               res += str[i];
        }
        cout << res << endl;
    }
    return 0;
}
