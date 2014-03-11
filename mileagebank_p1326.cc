#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int mile;
    int total = 0;
    while(cin >> str && str != "#")
    {
        if(str == "0")
        {
            cout << total << endl;
            total = 0;
            cin >> str;
            if(str == "#")
                return 0;
        }
        cin >> str >> mile >> str;
        if(str == "F")
        {
            total += mile + mile;
        }
        else if(str == "B")
        {
            total += mile + (int)((float)mile / 2 + 0.5);
        }
        else
        {
            if(mile < 500)
                total += 500;
            else
                total += mile;
        }
    }

    return 0;
}
