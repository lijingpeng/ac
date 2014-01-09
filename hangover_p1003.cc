#include <iostream>
using namespace std;

int main()
{
    float overHangTar = 0.0;
    while(cin >> overHangTar && overHangTar != 0.00)
    {
        float sumOverHang = 0.0;
        int nCards = 1;
        for(; sumOverHang < overHangTar; nCards++)
        {
            sumOverHang += 1.0 /( nCards + 1);
        }
        cout << nCards - 1 <<" card(s)" << endl;
    }
    return 0;
}
