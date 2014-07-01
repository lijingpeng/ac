/* 字典树Trie，利用字符串的公共前缀来降低时间开销
 * 查找效率为O(h)，h为字符串长度
 * 可用于词频的统计
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAXN = 26;
const char sCh = 'a';
const char eCh = '\0';

typedef struct TrieNode
{
    bool isStr;                             //是不是能形成字符串
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
            tmp->isStr = false;
            p->next[*s - sCh] = tmp;
        }
        p = p->next[*s - sCh];
        s++;
    }
    p->isStr = true;
}

int TrieSearch(Trie *root, const char *s)
{
    Trie *p = root;
    while(p != NULL && *s != eCh)
    {
        p = p->next[*s - sCh];
        s++;
    }
    return (p != NULL && p->isStr == true);
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
    int i, n, m; //n为建立Trie树输入的单词数，m为要查找的单词数 
    char s[100];
    Trie *root= (Trie *)malloc(sizeof(Trie));
    for(i=0;i<MAXN;i++)
    {
        root->next[i]=NULL;
    }

    root->isStr=false;
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)                 //先建立字典树 
    {
        scanf("%s",s);
        TrieInsert(root,s);
    }
    while(scanf("%d",&m)!=EOF)
    {
        for(i=0;i<m;i++)                 //查找 
        {
            scanf("%s",s);
            if(TrieSearch(root,s)==1)
                printf("YES\n");
            else
                printf("NO\n");
        }
        printf("\n");   
    }
    TrieDelete(root);                         //释放空间很重要 
    return 0;
}
