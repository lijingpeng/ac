#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n && n)
    {
        for(int i = 0; i < n; i++)
        {
            int num, min = 999999999;
            cin >> num;
            for(int x = 1; x <= num; x++)
            {
                for(int y = 1; y * x <= num; y++)
                {
                    if(num % (x*y) != 0)
                        continue;
                    else
                    {
                        int z = num / x / y;
                        int res = (x*y + x*z + y*z);
                        if(res < min)
                            min = res;
                    }
                }
            }
            cout << min * 2<< endl;
        }
    }
    return 0;
}
