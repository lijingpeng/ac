#include <iostream>
using namespace std;
typedef int Type;

int Partition(Type *a, int low, int high)
{
    int pivot_key = a[low];                         //记住中轴的数值
    while(low < high)
    {
        while(low < high && a[high] >= pivot_key)   //从后面找到第一个小于中轴值的数
            --high;
        a[low] = a[high];
        while(low < high && a[low] <= pivot_key)    //从前面找到第一个大于中轴值的数
            ++low;
        a[high] = a[low];
    }
    a[low] = pivot_key;                             //将中轴值移动到位置
    return low;
}

void Qsort(Type *a, int low, int high)
{
    if(low < high)
    {
        int p = Partition(a, low, high);            //将数组一分为二
        Qsort(a, low, p -1);                        //递归低子表
        Qsort(a, p + 1, high);                      //递归高子表
    }
}

void QuickSort(Type *a, int len)
{
    Qsort(a, 0, len - 1);
}

int main()
{
    int t;
    cin >> t;
    int a[10];
    for(int i = 0; i < t; i++)
        cin >> a[i];

    QuickSort(a, t);
    for(int i = 0; i < t; i++)
        cout << " " << a[i];
    cout << endl;
    return 0;
}
