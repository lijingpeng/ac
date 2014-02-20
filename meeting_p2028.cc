#include <iostream>
using namespace std;

int main()
{
    int n, least;
    while(cin >> n >> least && n && least)
    {
        int dates[101] = {0},  max = 0, index = 0;
        for(int i = 0; i < 101; i++)
            dates[i] = 0;
        for(int i = 0; i < n; i++)
        {
            int dtp;
            cin >> dtp;
            for(int j = 0; j < dtp; j++)
            {
                int dt;
                cin >> dt;
                dates[dt]++;
            }
        }

		   for(int j = 0; j < 101; j++)
            {
				if( max < dates[j])
				{
					max = dates[j];
					index = j;
				}
            }

        if(max >= least)
			cout << index << endl;
        else
           cout << "0" << endl; 
    }
    return 0;
}
