/* 折半查找
 * 只能在有序表中使用
 * 复杂度log2n
 */
#include <iostream>
using namespace std;
typedef int Type;

/* params:array[]
 * params:key, what you want to find
 * params:length, length of the array
 * return index of key, -1 for not found
 */
int BiSearch(Type *array, Type key, int length)
{
    int low = 0, high = length - 1, mid = 0;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(array[mid] == key)
            return mid;
        else if(array[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1; // not found
}

int main()
{
    int t,s;
    cin >> t;
    int a[10];
    for(int i = 0; i < t; i++)
        cin >> a[i];

    cin >> s;
    cout << BiSearch(a, s, t) << endl;
    return 0;
}
