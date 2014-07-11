#include <iostream>
#include <algorithm>

using namespace std;

#define ULL unsigned long long int

int main()
{
	ULL a, b;
	while (cin >> a >> b && (a || b))
	{
		if (b > a) swap(a, b);
		ULL s = 1, i, j;
		for (i = a + 1, j = 1; i <= a + b; i++, j++)
		{
			s = s * i / j;
		}
		cout << s << endl;
	}
}
