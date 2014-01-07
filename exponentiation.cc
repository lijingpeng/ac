/**************************************
 * R exp(n)
 * R is a rational number, 0<= n <=25
 * return resutlt
 * ***********************************/

#include <iostream>
using namespace std;
typedef int IntegerType;

const int MAX = 1024;

int main()
{
    string r, n;
    while(cin >> r >> n)
    {
        const char *nTmp = n.c_str();
        int dotPos = 0;
        dotPos = r.find('.');
        dotPos = dotPos == string::npos ? 0: dotPos;
        int rLen = r.length();

        string pureNum("");
        int startPos = 0, endPos = 0;
        if(dotPos) // has dot
        {
            string tmp = r.substr(0, dotPos);
            if(tmp[0] != '0')
                pureNum += tmp;

            tmp = r.substr(dotPos + 1);
            cout << "fefe" << tmp;
            int tmpLen = tmp.length();
            for(int i=tmpLen; i >= 0; i--)
            {
                if(tmp[i] != '0')
                {
                    endPos = i;
                }
            }
            pureNum += tmp.substr(0, endPos);
            //if()
        }
        cout << pureNum << " " << n << endl;
        cout << dotPos << endl;
    }
    return 0;
}
