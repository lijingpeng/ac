#include <iostream>
using namespace std;

int main()
{
    int sum, num[100], tnum[202];
    while(cin >> num[0] && num[0] != -1)
    {
        for(int i = 0; i < 202; i++) tnum[i] = 0;

        sum = 1;
        tnum[ num[0] ] = 1;
        while(cin >> num[sum] && num[sum] != 0)
        {
            tnum[ num[sum] ] = 1;
            sum++;
        }

        int tsum=0;
        for(int i = 0; i < sum; i++)
        {
            if(tnum[ num[i] * 2 ] == 1)
            {
                tsum++;
            }
        }
        cout << tsum << endl;
    }
      return 0;
}
