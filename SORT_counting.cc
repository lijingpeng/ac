/* 计数排序
 * 复杂度O(n)
 * 输入元素不需要相互比较，假设每个输入元素都是介于0 ～ k之间的数字
 * 稳定排序
 */
#include <iostream>
#include <memory.h>
using namespace std;
typedef int Type;
int count[100];

void CountingSort(Type *a, Type *b, int lena, int k)
{
    memset(count, 0, sizeof(count));
    for(int i = 0; i < lena; ++i)
        count[a[i]]++;
    for(int i = 0; i < k; ++i)
        count[i] += count[i - 1];
    for(int i = lena - 1; i >= 0; --i)
    {
        b[count[a[i]] - 1] = a[i];
        count[a[i]] -= 1;
    }
}

/*
 * 8 2 5 3 0 2 3 0 3
 *  0 0 2 2 3 3 3 5
 */
int main()
{
    int t;
    cin >> t;
    int a[10], b[10];
    for(int i = 0; i < t; i++)
        cin >> a[i];

    CountingSort(a, b, t, 10);
    for(int i = 0; i < t; i++)
        cout << " " << b[i];
    cout << endl;
    return 0;
}
