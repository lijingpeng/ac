/* 冒泡排序
 * 复杂度O(n^2)
 */
#include <iostream>
using namespace std;
typedef int Type;

void BubbleSwap(Type *a, int len)
{
    for(int i = 0; i < len - 1; ++i)
    {
        if(a[i] > a[i+1])
        {
            a[i] ^= a[i+1];
            a[i+1] ^= a[i];
            a[i] ^= a[i+1];
        }
    }
}

void BubbleSort(Type *a, int len)
{
    for(int i = len; i > 0; --i)
        BubbleSwap(a, i);
}

/* test data
 * 8
 * 49 38 65 97 76 13 27 49
 *  13 27 38 49 49 65 76 97
 */
int main()
{
    int t;
    cin >> t;
    int a[10];
    for(int i = 0; i < t; i++)
        cin >> a[i];

    BubbleSort(a, t);
    for(int i = 0; i < t; i++)
        cout << " " << a[i];
    cout << endl;
    return 0;
}
