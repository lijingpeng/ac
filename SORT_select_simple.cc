/* 简单选择排序
 * 复杂度O(n^2)
 */
#include <iostream>
using namespace std;
typedef int Type;

int SelectMin(int *a, int s, int len)
{
    int i, mk = a[s], mi = s;
    for(i = s + 1; i < len; ++i)
    {
        if(mk > a[i])
        {
            mk = a[i];
            mi = i;
        }
    }
    return mi;
}

void SelectSort(int *a, int len)
{
    int i, j;
    for(i = 0; i < len; ++i)
    {
        j = SelectMin(a, i, len);
        cout << j;
        if(i != j)
        {
            a[i] ^= a[j];
            a[j] ^= a[i];
            a[i] ^= a[j];
        }
    }
}

int main()
{
    int t;
    cin >> t;
    int a[10];
    for(int i = 0; i < t; i++)
        cin >> a[i];

    SelectSort(a, t);
    for(int i = 0; i < t; i++)
        cout << " " << a[i];
    cout << endl;
    return 0;
}
