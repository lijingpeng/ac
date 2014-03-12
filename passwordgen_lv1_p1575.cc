#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    while(cin >> str && str != "end")
    {
        int vcnt = 0, ccnt = 0, scnt = 1;
        int avg = 0, vcg = 0, sg = 0;
        for(int i = 0; i < str.length(); i++)
        {
            // the same
            if(i > 0 && str[i] == str[i - 1] && str[i] != 'e' && str[i] != 'o')
                scnt++;
            else
                scnt = 1;

            if(scnt == 2)
            {
                sg = 1; break;
            }

            // at least one vowel
            if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') // vowel
            {
                avg = 1; // vowel
                vcnt++;
                ccnt = 0;
                if(vcnt == 3)
                {
                    vcg = 1; break;
                }
            }
            else
            {
                ccnt++;
                vcnt = 0;
                if(ccnt == 3)
                {
                    vcg = 1; break;
                }
            }
        }

        if(!vcg && avg && !sg)
            cout << "<" << str <<"> is acceptable." << endl;
        else
            cout << "<" << str << "> is not acceptable." << endl;
       
    }

    return 0;
}
