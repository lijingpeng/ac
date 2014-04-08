#include <iostream>
using namespace std;

char calc(char a)
{
        if(a=='B'||a=='F'||a=='P'||a=='V') return '1';
        if(a=='C'||a=='G'||a=='J'||a=='K'||a=='Q'||a=='S'||a=='X'||a=='Z') return '2';
        if(a=='D'||a=='T') return '3';
        if(a=='L') return '4';
        if(a=='M'||a=='N') return '5';
        if(a=='R') return '6';
        else return ' ';
}
int main()
{
    string str;
    while(cin >> str && str != "#")
    {
        char prev = ' ';
        for(int i = 0; i < str.length(); i++)
        {
            char c = calc( str[i] );
           if(calc(prev) != c && c != ' '  )
                cout << c;

            prev = str[i];
        }
        cout << endl;
    }
    return 0;
}
