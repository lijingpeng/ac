#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    int n, max = 11, min = 0;
    string str;
    while(1)
    {
        max = 11;
        min = 0;
        while(cin >> n )
        {
            if( n == 0 ) return 0;
            cin >> str >> str;
            if(str == "high" )
            {
                if( n < max )
                    max = n;
            }
            else if(str == "low" )
            {
                if( n > min )
                    min = n;
            }
            else if(str == "on")
            {
                break;
            }
        }
        if(n >= max || n <= min)
            cout << "Stan is dishonest" << endl;
        else
            cout << "Stan may be honest" << endl;
    }
    return 0;
}
