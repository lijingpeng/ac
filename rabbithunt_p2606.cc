#include <iostream>
using namespace std;

struct Point
{
    float x;
    float y;
};
int main()
{
    int n;
    struct Point pt[200];
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
                    if( (pt[i].x - pt[j].x)*(pt[j].y - pt[k].y) == (pt[i].y - pt[j].y)*(pt[j].x - pt[k].x) )
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
