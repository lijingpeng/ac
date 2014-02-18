#include <iostream>
using namespace std;
const int MAX = 51;
int main()
{
    int sets = 0, stacks[51] = {0}, n, sum = 0;
    while(cin >> n && n)
    {
        sum = 0;
        cout << "Set #" << ++sets << endl;
        for(int i = 0; i < n; i++)
        {
            cin >> stacks[i];
            sum += stacks[i];
        }

        int avg = sum / n;
        sum = 0;
        for(int i = 0; i < n; i++)
        {
            int move = avg - stacks[i];
            if(move > 0)
                sum += move;
        }
        cout << "The minimum number of moves is " << sum << "." << endl<<endl;
    }
    return 0;
}
