#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
const int MX = 26;

/* Sunday算法
 * 字符串模式匹配中超越BF、KMP和BM的算法
 * 核心思想：如果该字符没有在匹配串中出现则直接跳过，即移动步长= 匹配串长度+1；否则，同BM算法一样其移动步长=匹配串中最右端的该字符到末尾的距离+1。
 * 时间复杂度：
 * 预处理O(M)
 * 总的时间复杂度O(N*M),但是一般情况下具有很好的性能
 */
int SundayStringMatch(const char *str, const char *subStr)
{
    int lenSrc = strlen(str);
    int lenSub = strlen(subStr);
    if(str == NULL || subStr == NULL || lenSrc < lenSub)
        return -1;

    int next[MX] = {0};
    for(int i = 0; i < MX; ++i)
        next[i] = lenSub + 1;
    for(int i = 0; i < lenSub; ++i)
        next[ subStr[i] - 'a' ] = lenSub - i;   ////记录字符到最右段的最短距离+1  
    /*例如：des = "abcedfb"
     * next = {7 1 5 4 3 2 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8}  
     */
    
    int pos = 0;
    while(pos < (lenSrc - lenSub + 1))
    {
        int i = pos, j = 0;
        for(j = 0; j < lenSub; ++j, ++i)
        {
            if(str[i] != subStr[j])
            {
                pos = pos + next[ str[pos + lenSub] - 'a' ];    //核心思想，不等于的时候就跳跃
                break;
            }
        }

        if(j == lenSub)
            return pos;
    }
    return -1;
}

int main()
{
    char src[]="abcdacdaahfacabcdabcdeaa";  
    char des[]="abcde";  
    cout<< SundayStringMatch(src,des)<<endl;
    return 0;
}
