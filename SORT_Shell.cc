/* 希尔排序
 * 复杂度O(nlogn)
 */
#include <iostream>
using namespace std;
typedef int Type;

void ShellInsert(Type *array, int dk, int len)
{
    int i, j, tmp;
    for(i = dk; i < len; i += dk)
    {
        tmp = array[i];
        for(j = i - dk; j >=0 && array[j] > tmp; j -= dk)
            array[j + dk] = array[j];
        array[j + dk] = tmp;
    }
}

void ShellSort(Type *array, int *dk, int len_dk, int len)
{
    int i;
    for(i = 0; i < len_dk; ++i)
        ShellInsert(array, dk[i], len);
}

/* test data
 * 10
 * 49 38 65 97 76 13 27 49 55 04
 *  4 13 27 38 49 49 55 65 76 97
 */
int main()
{
    int t;
    cin >> t;
    int a[10];
    for(int i = 0; i < t; i++)
        cin >> a[i];

    int dk[] = {9, 5, 3, 2, 1};
    ShellSort(a, dk, 5, t);
    for(int i = 0; i < t; i++)
        cout << " " << a[i];
    cout << endl;
    return 0;
}
