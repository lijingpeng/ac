#include <iostream>
using namespace std;

int pows[] = {128, 64, 32, 16, 8, 4, 2, 1};
int main()
{
    int n;
    string bin;
    while(cin >> n && n)
    {
        for(int j = 0; j < n; j++)
        {   
            cin >> bin;
            int sum = 0;
            for(int i = 0; i < bin.length(); i++)
            {
                if(i % 8 == 0 && i != 0)
                {
                    cout << sum << ".";
                    sum = 0;
                }
                if(bin[i] == '1')
                    sum += pows[ i % 8 ];
            }
            cout << sum << endl;
        }
    }
    return 0;
}
