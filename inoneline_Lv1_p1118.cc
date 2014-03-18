#include <iostream>
using namespace std;

struct Point
{
    int x;
    int y;
};
int main()
{
    int n, a, b;
    struct Point pt[702];
    while(cin >> n && n)
    {
        int sum = 0, max = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> pt[i].x >> pt[i].y;
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1;j < n; j++)
            {
                sum = 0;
                for(int k = j + 1; k < n; k++)
                {
                    a =  (pt[i].x - pt[j].x)*(pt[j].y - pt[k].y) ;
                    b =  (pt[i].y - pt[j].y)*(pt[j].x - pt[k].x); 
                    if(a == b)
                        sum++;
                    if(sum > max)
                        max = sum;
                }
            }
        }

        cout << max + 2 << endl;
    }
    return 0;
}
