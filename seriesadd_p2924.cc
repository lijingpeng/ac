#include <iostream>
using namespace std;

int main()
{
    int se, cnt = 0;
    long long n, m;
    while(cin >> se && se)
    {
        for(int i = 0; i < se; i++)
        {
            cout << "Scenario #" << ++cnt << ":" << endl;
            cin >> n >> m;   
            //printf("%.0lf\n\n",  (n + m) * (m - n + 1) / 2 );
			cout << (n + m) * (m - n + 1) / 2 << endl << endl;
        }
    }
    return 0;
}
