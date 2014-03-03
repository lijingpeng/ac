#include <iostream>
using namespace std;

int main()
{
    int k, m, cls[10000], tmp;
    while(cin >> k && k)
    {
        for(int i = 0; i < 10000; i++) cls[i] = 0;
        cin >> m; //cat num
        for(int i = 0; i < k; i++)
        {
            cin >> tmp;
            cls[tmp] = 1;
        }

        int cnum, cmin, cnt = 0, flag = 0;
        for(int j = 0; j < m; j++)
        {
            cnt = 0;
            cin >> cnum >> cmin;
            for(int i = 0; i < cnum; i++)
            {
                cin >> tmp;
                if(cls[tmp] == 1)
                    cnt++;
            }

            if(cnt < cmin)
            {
                flag = 1;
            }
        }
        if( !flag )
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}
