/* 字典树Trie，利用字符串的公共前缀来降低时间开销
 * 查找效率为O(h)，h为字符串长度
 * 可用于词频的统计
 */
#include <iostream>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAXN = 26;
const char sCh = 'a';
const char eCh = '\0';

typedef struct TrieNode
{
    int count;
    struct TrieNode *next[MAXN];            //儿子节点，多叉树
}Trie;

void TrieInsert(Trie *root, const char *s)
{
    if(root == NULL || *s == eCh)
        return;
    Trie *p = root;
    while(*s != eCh)
    {
        if(p->next[*s - sCh] == NULL)       //不存在，插入
        {
            Trie *tmp = (Trie *)malloc(sizeof(Trie));
            for(int i = 0; i < MAXN; ++i)
            {
                tmp->next[i] = NULL;
            }
            tmp->count = 0;
            p->next[*s - sCh] = tmp;
        }
        p = p->next[*s - sCh];
        p->count++;
        s++;
    }
}

int TrieSearch(Trie *root, const char *s)
{
    Trie *p = root;
    while(p != NULL && *s != eCh)
    {
        if(p->count == 1)
            break;

        printf("%c", *s);
        p = p->next[*s - sCh];
        s++;
    }
    printf("\n");
    return (p != NULL);
}

void TrieDelete(Trie *root)
{
    for(int i = 0; i < MAXN; ++i)
    {
        if(root->next[i] != NULL)
            TrieDelete(root->next[i]);
    }
    free (root);
}

int main()
{
    int i = 0, m = 0; //n为建立Trie树输入的单词数，m为要查找的单词数 
    char s[1001][26];
    memset(s, 0, sizeof(s));
    Trie *root= (Trie *)malloc(sizeof(Trie));
    for(i=0;i<MAXN;i++)
        root->next[i]=NULL;
    root->count = 0;
    
    while(scanf("%s", s[m]) != EOF)
    {
        TrieInsert(root, s[m]);
        ++m;
    }

    for(int j = 0; j < m; ++j)
    {
        printf("%s ", s[j]);
        TrieSearch(root, s[j]);
    }

    printf("\n");   
    TrieDelete(root);                         //释放空间很重要 
    return 0;
}
