#include <iostream>
#include <cmath>
using namespace std;

int min(int a, int b, int c, int d)
{
    int mini = 2099999999;
    mini = mini < a ? mini : a;
    mini = mini < b ? mini : b;
    mini = mini < c ? mini : c;
    mini = mini < d ? mini : d;
    return mini;
}

int main()
{
    int n, hset[5843];
    hset[1] = 1;
    int c2 = 1, c3 = 1, c5 = 1, c7 = 1, c = 2;
    while(c < 5843)
    {
        hset[c] = min(hset[c2]*2, hset[c3]*3, hset[c5]*5, hset[c7]*7);
        if(hset[c] == hset[c2]*2)
            c2++;
        if(hset[c] == hset[c3]*3)
            c3++;
        if(hset[c] == hset[c5]*5)
            c5++;
        if(hset[c] == hset[c7]*7)
            c7++;
        c++;
    }

    while(cin >> n && n)
    {
        cout << "The " << n;
        if(n % 10 == 1 && n % 100 != 11)       
            cout << "st";
        else if(n % 10 == 2 && n % 100 != 12)
            cout << "nd";
        else if(n % 10 == 3 && n % 100 != 13)
            cout << "rd";
        else
            cout << "th";
        cout << " humble number is " << hset[n] << "." << endl;
    }
    return 0;
}
