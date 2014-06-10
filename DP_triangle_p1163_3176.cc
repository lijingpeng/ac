#include <iostream>
using namespace std;
int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    int n, i, j;
    cin >> n;
    int **way = new int*[n + 1]; // 0 ~ n, the first column, refers to one line (array)

    for(i = 0; i <= n; ++i)
    {
        way[i] = new int[i + 2]; // one more int for each line
        for(j = 0; j < i + 2; ++j)
            way[i][j] = 0;       // can not use memset

        if(i != 0)
        {
            for(j = 1; j < i + 1; ++j)
                cin >> way[i][j];
        }
    }

    //DP
    int maxres = -9999;
    for(i = 1; i <= n; ++i)
    {
        for(j = 1; j <= i; ++j)
        {
            way[i][j] += max(way[i - 1][j - 1], way[i - 1][j]);
            if(i == n && way[i][j] > maxres)
                maxres = way[i][j];
        }
    }
    cout << maxres << endl; 
    delete[] way;
    return 0;
}
