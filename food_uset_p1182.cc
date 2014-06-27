#include <iostream>
#include <cstdio>
 
using namespace std;
 
const int N=50001;
 
int parent[N];
int relation[N];
 
void makeSet(int i)
{
    parent[i]=i;
    relation[i]=0;
}
 
int find(int x)
{
    int temp;
 
    if(x!=parent[x])
    {
        temp=parent[x];
        parent[x]=find(parent[x]);
        relation[x]=(relation[x]+relation[temp])%3;
    }
    return parent[x];
}
 
void unionSet(int a, int b, int d)
{
    parent[a]=b;
    relation[a]=d%3;
}
 
int main()
{
    int n,k;
    int a,b,d;
    int cnt;
 
    scanf("%d%d",&n,&k);
 
    cnt=0;
    for(int i=1;i<=n; i++)
    {
        makeSet(i);
    }
 
    for(int i=1; i<=k; i++)
    {
        scanf("%d%d%d",&d,&a,&b);
        if(a>n || b>n)
        {
            cnt++;
            continue;
        }
        if(d==2 && a==b)
        {
            cnt++;
            continue;
        }
        else
        {
            int pa=find(a);
            int pb=find(b);
            if(pa!=pb)                                  //pa与pb不在同一集合就进行合并
                unionSet(pa,pb,relation[b]-relation[a]+d+2);
            else                                           //否则按上述所说进行处理
            {
                if(d==1)
                {
                    if(relation[a]!=relation[b])
                        cnt++;
                }
                else
                {
                    if(relation[a]!=(relation[b]+1)%3)
                        cnt++;
                }
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
