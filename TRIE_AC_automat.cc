#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <string.h>
#include <memory.h>
using namespace std;
const int MAXN = 26;
const char sCh = 'a';
const char eCh = '\0';

typedef struct ACTrieNode
{
    int count;
    struct ACTrieNode *child[MAXN];            //儿子节点，多叉树
    struct ACTrieNode *fail;

    ACTrieNode()
    {
        count = 0;
        fail  = NULL;
        for(int i = 0; i < MAXN; i++)
            child[i] = NULL;
    }
}ACTrie;

void ACTrieInsert(ACTrie *root, const char *s)
{
    int lens = strlen(s);
    ACTrie *p = root;
    for(int i = 0; i < lens; ++i)
    {
        int diff = s[i] - sCh;
        if(p->child[diff] == NULL)
        {
            p->child[diff] = new ACTrieNode();
        }
        p = p->child[diff];
    }
    p->count++;
}

void BuildFailPointer(ACTrie *root)
{
    root->fail = NULL;
    queue<ACTrie*> myq;
    ACTrie *qFront = NULL, *pFail = NULL;
    myq.push(root);
    while( !myq.empty() )
    {
        qFront = myq.front();
        myq.pop();
        pFail = NULL;
        for(int i = 0; i <MAXN; ++i)
        {
            if(qFront->child[i] == NULL) continue;
            if(qFront == root)
            {
                qFront->child[i]->fail = root;
                myq.push(qFront->child[i]);
                continue;
            }

            pFail = qFront->fail;                                       //父亲的失败指针
            while(pFail != NULL)                                        //父亲的失败指针是有效的
            {
                if(pFail->child[i] != NULL)                             
                {
                    qFront->child[i]->fail = pFail->child[i];           //！！当前节点的失败指针指向《沿着父亲失败
                    break;                                              //节点走，知道某节点的儿子节点中有相同字母》
                }
                pFail = pFail->fail;
            }

            if(pFail == NULL)
                qFront->child[i]->fail = root;                          //找不到的话指向root节点

            myq.push(qFront->child[i]);                                 //处理子节点
        }
    }
}

int ACTrieQuery(ACTrie *root, const char *s)
{
    ACTrie *p = root;
    int lens = strlen(s), cnt = 0;
    for(int i = 0; i < lens; ++i)
    {
        int diff = s[i] - sCh;
        while(p->child[diff] == NULL && p != root)
            p = p->fail;                                                //找不到的话，沿着失败节点找

        p = p->child[diff];
        p = (p == NULL) ? root : p;
        ACTrie *tmp = p;
        while(tmp != root && tmp->count != -1)
        {
            cnt += tmp->count;
            tmp->count = -1;
            tmp = tmp->fail;
        }
    }
    return cnt;
}

int main()
{
    int T;
    int n;
    char str[1000005];  //模式串
    char s[51];
    scanf("%d",&T);
    while(T--)
    {
        ACTrie *root = new ACTrieNode();
        scanf("%d",&n);
        getchar();
        while(n--)
        {
            scanf("%s",s);
            ACTrieInsert(root, s);
        }
        BuildFailPointer(root);
        scanf("%s",str);
        printf("%d\n",ACTrieQuery(root, s));
    }
    return 0;
}
