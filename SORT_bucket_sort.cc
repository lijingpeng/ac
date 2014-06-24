/* 桶排序
 * 适用于元素均匀分布
 * 复杂度O(n)
 */
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <memory.h>
using namespace std;
typedef int Type;
const int MAX_NUM = 10;

struct bucket_node{
    Type data[MAX_NUM];
    int count;
};

typedef bucket_node bucket;
/* suppose all numbers are less then 100
 */
void BucketSort(Type *a, int len)
{
    int maxDig = a[0];
    int minDig = maxDig;
    for(int i = 1; i < len; ++i)
    {
        if(maxDig < a[i])
            maxDig = a[i];
        else if(minDig > a[i])
            minDig = a[i];
    }

    int bucketCount = (maxDig - minDig + 1) / 10 + 1;       //需要桶的个数
    bucket *pBucket = (bucket *)malloc(sizeof(bucket_node) * bucketCount);
    memset(pBucket, 0, sizeof(bucket_node) * bucketCount);  //必须初始化
    for(int i = 0; i < len; ++i)                            //将元素放到不同的桶中
    {
        int pb = (a[i] - minDig + 1) / 10;
        (pBucket + pb)->data[(pBucket + pb)->count] = a[i];
        (pBucket + pb)->count++;
    }

    for(int i = 0, m = 0; i < bucketCount; ++i)
    {
        sort((pBucket + i)->data, (pBucket + i)->data + (pBucket + i)->count);  //桶内排序
        for(int j = 0; j < (pBucket + i)->count; ++j)                           //桶内排序完输出就可以
            a[m++] = (pBucket + i)->data[j];
    }
    free(pBucket);
}

int main()
{
    int t = 10;
    int a[10] = {78, 17, 39, 26, 72, 94, 21, 12, 23, 91};

    BucketSort(a, 10);
    for(int i = 0; i < t; i++)
        cout << " " << a[i];
    cout << endl;
    return 0;
}
