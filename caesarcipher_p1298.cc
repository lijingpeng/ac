#include <iostream>
#include <string>
using namespace std;

int main()
{
    string cipher;
    while(getline(cin, cipher) && cipher != "ENDOFINPUT")
    {
        getline(cin, cipher);
        string res = "";
        for(int i = 0; i < cipher.length(); i++)
        {
            if(cipher[i] >=65 && cipher[i] <= 90)
            {
                int ch = cipher[i] - 5;
                if(ch < 65)
                    ch += 26;
                res += ch;
            }
            else
                res += cipher[i];
        }
        cout << res << endl;
        getline(cin, cipher);
    }
    return 0;
}
