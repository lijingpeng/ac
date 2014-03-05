#include <iostream>
using namespace std;

int main()
{
    int n, seats[31];
    while(cin >> n && n)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> seats[i];
        }

        int i, j, sam[31], elle[31];
        for( i = 0; i < 31; i++)
        {
            sam[i] = 0;
            elle[i] = 0;
        }
        for(i = 0, j = n - 1; i < n && j >= 0; i++, j--)
        {
            sam[i] = seats[i] + sam[ i == 0 ? 0 : i - 1];
            elle[j]= seats[j] + elle[ j == n - 1 ? n - 1 : j + 1 ];
        }

        int flag = 0, sami = 0, elli = 0;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(i < j && j - i == 1 && sam[i] == elle[j])
                {
                    flag = 1;
                    sami = i;
                    elli = j;
                }
            }
        }

        if(flag)
            cout << "Sam stops at position " << sami + 1<< " and Ella stops at position " << elli + 1 << "." << endl;
        else
            cout << "No equal partitioning." << endl;
    }
    return 0;
}
