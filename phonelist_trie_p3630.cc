/* 字典树Trie，利用字符串的公共前缀来降低时间开销
 * 查找效率为O(h)，h为字符串长度
 * 可用于词频的统计
 */
#include <iostream>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAXN = 10;
const char sCh = '0';

typedef struct TrieNode
{
    bool isStr;                             //是不是能形成字符串
    struct TrieNode *next[MAXN];            //儿子节点，多叉树
}Trie;

Trie node[70010];
int nodeCount = 0, condition = 0;

void TrieInit()
{
    nodeCount = 1;
    condition = 0;
    for(int i = 0; i < 70010; ++i)
    {
        node[i].isStr = false;
        for(int j = 0; j < MAXN; ++j)
            node[i].next[j] = NULL;
    }
}

void TrieInsert(Trie *root, const char *s)
{
    int len = strlen(s);
    Trie *p = root;
    for(int i = 0; i < len; ++i)
    {
        int diff = s[i] - sCh;
        if(i == len - 1 && p->next[diff] != NULL) //s = 1 root = 12
        {
            condition = 1;
            return;
        }
        if(p->next[diff] != NULL)                   
        {
            if(p->next[diff]->isStr)            //s = 12 root = 1
            {
                condition = 1;
                return;
            }
            p = p->next[diff];
        }
        else
        {
           Trie *t = node + nodeCount++;
           t->isStr = false;
           p->next[diff] = t;
           p = p->next[diff];
        }
    }
    p->isStr = true;
}

int main()
{
    int t, n;
    char s[13] = {0};
    cin >> t;
    while(t--)
    {
        TrieInit();
        condition = 0;
        Trie *root=(Trie *)malloc(sizeof(Trie));
        for (int i=0; i<10; ++i)
        {
            root->next[i]=NULL;
        }
        cin >> n;
        for(int i = 0; i < n; ++i)
        {
            scanf("%s",s);
            if( condition == 0 )
            {
                TrieInsert(node, s);
            }
        }
        if(condition == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
