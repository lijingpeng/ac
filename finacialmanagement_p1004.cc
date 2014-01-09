
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double monSalary = 0.0, sumYear = 0.0;
    int mon = 0;
    
    for(mon = 1; mon < 13; mon++)
    {
        cin >> monSalary;
        sumYear += monSalary;
    }
    
    cout << fixed << setprecision(2) <<"$"<< sumYear/12.0<<endl;
    return 0;
}
