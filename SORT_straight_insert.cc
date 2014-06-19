/* 直接插入排序
 * 复杂度O(n^2)
 */
#include <iostream>
using namespace std;
typedef int Type;

/* params:array[]
 * params:length, length of the array
 */
void SortStraightInsert(Type *array, int length)
{
    int i, j, tmp;
    for(i = 1; i < length; ++i)
    {
        if(array[i] < array[i - 1])                 //和前一个元素比较
        {
            tmp = array[i];                         //记住当前的元素值
            for(j = i - 1; array[j] > tmp; --j)     //从当前元素向前比较
                array[j + 1] = array[j];            //前一个元素比当前的大则后移动
            array[j + 1] = tmp;                     //在适当位置插入当前元素
        }
    }
}
int main()
{
    int t,s;
    cin >> t;
    int a[10];
    for(int i = 0; i < t; i++)
        cin >> a[i];

    SortStraightInsert(a, t);
    for(int i = 0; i < t; i++)
        cout << " " << a[i];
    cout << endl;
    return 0;
}
