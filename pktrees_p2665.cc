#include <iostream>
using namespace std;

int main()
{
    long m, sum = 0;
    int sec, start, end;
	while(cin >> m >> sec && m != 0)
	{
		sum = m + 1;
		for(int i = 0; i < sec; i++)
		{
		    cin >> start >> end;
		    sum -= (end - start);
		}
		cout << sum - sec << endl;
	}
    return 0;
}
