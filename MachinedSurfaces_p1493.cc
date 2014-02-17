#include <iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
const int MAX = 16;
int main()
{
    int n,i,j;
    while(cin >> n && n != 0)
    {
		int xsum[MAX] = {0}, xmax = 0;
        cin.get();
		string s;
	    for(i = 0; i < n; i++)
	    {
		getline(cin, s);    
		for(j = 0; j < s.length(); j++)
		{
		    if(s[j] == 'X')
		        xsum[i]++;
		}
		if(xsum[i] > xmax)
		    xmax = xsum[i];
	    }
	    int sum = 0;
	    for(i = 0; i < n; i++)
		sum += (xmax - xsum[i]);

	    cout << sum << endl;
    }
    return 0;
}
