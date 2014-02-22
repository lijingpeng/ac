#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
    int t;
    while(cin >> t && t)
    {
        string clStr;
        for(int i = 0; i < t; i++)
        {
            cin >> clStr;
            int mPos = clStr.find(":");
            string mStr = clStr.substr(mPos + 1);
            if(mStr == "00")
            {
                clStr = clStr.substr(0, mPos);
                int times = atoi(clStr.c_str());
                times + 12 > 24 ? cout << times - 12 << endl : cout << times + 12 << endl;
            }
            else
            {
                cout << "0" << endl;
            }
        }
    }
    return 0;
}
