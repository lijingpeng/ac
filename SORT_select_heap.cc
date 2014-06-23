/* 堆排序
 * 最坏情况下复杂度O(nlogn)
 */
#include <iostream>
#include <algorithm>
using namespace std;
typedef int Type;

void HeapAdjust(Type *a, int si, int size)
{
    Type parent = a[si];
    int i;
    for(i = 2 * si + 1; i <= size; i *= 2)
    {
        if(i < size && a[i] < a[i + 1])
            i++;
        if(parent > a[i])                   //父亲节点大于子节点
            break;

        a[si] = a[i];                       //父亲小于儿子节点，交换
        si = i;                             //将交换之后的序列调整成堆
    }
    a[si] = parent;
}

void HeapSort(Type *a, int len)
{
    int i;
    for(i = len/2; i >= 0; --i)
        HeapAdjust(a, i, len);
    for(i = len - 1; i > 0; --i)
    {
        //a[i] ^= a[0];
        //a[0] ^= a[i];
        //a[i] ^= a[0];
        Type tmp = a[i];
        a[i] = a[0];
        a[0] = tmp;

        HeapAdjust(a, 0, i - 1);
    }
}
int main()
{
    int t;
    cin >> t;
    int a[10] = {0};
    for(int i = 0; i < t; i++)
        cin >> a[i];

    for(int i = 0; i < t; i++)
        cout << " " << a[i];
    cout << endl;
    HeapSort(a, t);
    for(int i = 0; i < t; i++)
        cout << " " << a[i];
    cout << endl;
    return 0;
}
