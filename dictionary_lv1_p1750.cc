#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    char ss[12][13] = {
    "",
    " ",
    "  ",
    "   ",
    "    ",
    "     ",
    "      ",
    "       ",
    "        ",
    "         ",
    "          ",
    "            "
    };
    string str, pstr;
    cin >> str;
    cout << str << endl;
    pstr = str;
    int i, com = 1;
    char s[20];
    while(scanf("%s", s) != EOF)
    {
        string str(s);
        for(i = 0; i < com; i++)
        {
            if(pstr[i] != str[i])
            {
                com = i;
                break;
            }
        }

        com++;
                        
        cout << ss[com - 1] << str << endl;;

        pstr = str;
    }

    return 0;
}
