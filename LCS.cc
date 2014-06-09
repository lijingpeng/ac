#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <memory.h>
using namespace std;
const int MAX = 100;

int lcs_length(const char *x, const char *y, int xlen, int ylen, int (*c)[MAX])
{
    int i, j;
    for(i = 1; i <= xlen; ++i)
    {
        for(j = 1; j <= ylen; ++j)
        {
            if(x[i - 1] == y[j - 1])
                c[i][j] = c[i - 1][j - 1] + 1;
            else if(c[i - 1][j] >= c[i][j - 1])
                c[i][j] = c[i - 1][j];
            else
                c[i][j] = c[i][j - 1];
        }
    }
    return 0;
}

int print_lcs(const int (*C)[MAX], const char *x, int i, int j, string &s)
{
   if(i == 0 || j == 0) 
       return 0;
   if(C[i][j-1] == C[i-1][j] && C[i][j] > C[i-1][j-1] && C[i][j] != C[i][j-1] && C[i][j] != C[i-1][j])
   {
       //cout << x[i - 1];
       s += x[i - 1];
       print_lcs(C, x, i - 1, j - 1, s);
   }
   else if(C[i][j-1] > C[i-1][j])
       print_lcs(C, x, i, j - 1, s);
   else
       print_lcs(C, x, i - 1, j, s);
}

int main()
{
    int C[MAX][MAX];
    memset(C, 0, sizeof(C));
    int xlen, ylen;
    cin >> xlen >> ylen;
    char X[MAX], Y[MAX];
    scanf("%s%s", X, Y);
    string s = "";
    lcs_length(X, Y, xlen, ylen, C);
    print_lcs(C, X, xlen, ylen, s);
    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}
