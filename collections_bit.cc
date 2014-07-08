#include <iostream>
using namespace std;
#define DEBUG_BIT

//get int max with BIT
int get_max_int()
{   //2147483647
    return ((unsigned int) - 1) >> 1;
}

long get_max_long()
{   //9223372036854775807
    return ((unsigned long) - 1) >> 1;
}

int power(int n, int m)
{   //n* (2 ^ m)
    return n << (m - 1);
}

int is_odd_number(int n)
{   // 1 for odd number, 1 for even number
    return (n & 1) == 1;
}

int is_factor_two(int n)
{   // 是不是2的幂，n must be 10000... and n -1 must be 1111... (after and) the result is 0
    return n > 0 ? (n & (n - 1)) == 0 :false;
}

int get_bit(int n, int m)
{   // 获得n的第m位，将n右移动m-1位，现在的第一位就是原来的第m位
    return (n >> (m - 1)) & 1;
}

/**
 * 1 << (m -1): find the m position, 100000...
 * then set to 1
 */
int set_bit2one(int n, int m)
{
    return (n) | (1 << (m - 1));
}

/**
 * 1 << (m - 1):find the m'th position, 1000...
 * ~  : not this, to 1111...0..1111
 * and this
 */
int set_bit2zero(int n, int m)
{
    return (n) & ~(1 << (m - 1));
}

void swap(int *a, int *b)
{   //swap two number without temp
    (*a) ^= (*b);
    (*b) ^= (*a);
    (*a) ^= (*b);
}

/* 统计一个数字的二进制表示中1的个数
 * 原理：把一个整数减去1,再和原整数做与运算，会把最右边的1变成0
 * 例如1100-1=1011, 1100&1011=1000
 * 时间复杂度：有多少1就进行多少次这样的操作
 */
int countone(int n)
{
    int count = 0;
    while(n)
    {
        ++count;
        n = (n - 1) & n;
    }
    return count;
}

int main()
{
#ifdef DEBUG_BIT
    cout << get_max_int() << endl;
    cout << get_max_long() << endl;
    cout << power(2, 0) << endl;
    int sa = 1, sb = 2;
    swap(sa, sb);
    cout << sa << " " << sb << endl;
    int a = 15;
    cout << set_bit2zero(a, 3) << endl;
    cout << a << endl;
    for(int i = 1; i < 20; i++)
        cout << i << " " << (i & (-i)) << "\n";
#endif
    return 0;
}
