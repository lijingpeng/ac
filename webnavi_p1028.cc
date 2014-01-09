#include <iostream>
#include <stack>
#include <string>
using namespace std;

void popall(stack<string> &s)
{
    for(; !s.empty(); )
        s.pop();
}

int main()
{
    string cmd("");
    stack<string> sForward;
    stack<string> sBackword;
    string currentURL("http://www.acm.org/");
    sBackword.push(currentURL);
    while(getline(cin, cmd) && cmd != "QUIT")
    {
        if(cmd[0] == 'V')
        {
            string tmp = cmd.substr(cmd.find(" ") + 1);
            cout << tmp << endl;
            sBackword.push(tmp);
            popall(sForward);
        }
        else if(cmd == "BACK")
        {
            if(sBackword.size() < 2)
            {
                cout << "Ignored" << endl;
            }
            else
            {
                sForward.push(sBackword.top());
                sBackword.pop();
                cout << sBackword.top() << endl;
            }
        }
        else
        {
            if(sForward.empty())
            {
                cout << "Ignored" << endl;
            }
            else
            {
                cout << sForward.top() << endl;
                sBackword.push(sForward.top());
                sForward.pop();
            }
        }
    }
    return 0;
}
