#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int lineCnt = 0;
    while(cin >> lineCnt)
    {
        for(int i = 0; i < lineCnt; i++)
        {
            float x = 0.0, y = 0.0;
            cin >> x >> y;
            cout << "Property "<< i+1 << ": " << "This property will begin eroding in year " << ceil(3.1415*(x*x + y*y)/100) << "." <<endl;
        }
        cout << "END OF OUTPUT." << endl;
    }
    return 0;
}
