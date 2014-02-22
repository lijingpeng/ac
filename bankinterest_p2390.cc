#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int r, m, y;
    double prof = 0.0;
    while(cin >> r >> m >> y)
    {
		prof = m * pow(1 + r / 100.0, y);
        cout << (int)prof << endl;
    }
    return 0;
}
