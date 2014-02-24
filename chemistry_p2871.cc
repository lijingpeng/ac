#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    float prev, temp;
    cin >> prev;
    while(cin >> temp && temp != 999)
    {
        printf("%.2f\n", temp - prev);
        prev = temp;
    }
    cout << "End of Output" << endl;
    return 0;
}
