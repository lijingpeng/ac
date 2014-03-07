#include <iostream>
using namespace std;

int main()
{
    int num[12001];
    for(int i = 0; i < 12001; i++)
        num[i] = 1;

    for(int i = 1; i < 10001; i++)
    {
        int m = i, k = i;
        while(k)
        {
            m += k % 10;
            k /= 10;
        }
        num[ m ] = 0;
    }
    for(int i = 1; i < 10001; i++)
        if(num[i] == 1)
            cout << i << endl;
    
    return 0;
}
