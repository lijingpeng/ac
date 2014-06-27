#include <stdio.h>
const int MAXN = 1000001;
int parent[MAXN];
int ranks[MAXN];
int relation[MAXN];

void make_set(int x)
{
    parent[x] = x;
    ranks[x]  = 0;
    relation[x] = 0;
}

int find_set(int x)
{
    if(x != parent[x])
        parent[x] = find_set(parent[x]);
    return parent[x];
}

void union_set(int x, int y)
{
    if(ranks[x] > ranks[y])
        parent[y] = x;
    else
    {
        parent[x] = y;
        if(ranks[x] == ranks[y])
            ranks[y]++;
    }
}

int main()
{
    int t, n, m, x, y, s = 0;
    scanf("%d", &t);
    while( t-- )
    {
        scanf("%d%d", &n, &m);
        for(int i = 0; i <= n; ++i)
            make_set(i);

        int gay = 0;
        for(int i = 0; i < m; ++i)
        {
            scanf("%d%d", &x, &y);            
            int px = find_set(x);
            int py = find_set(y);
            
            if(relation[px] == 0)
                relation[px] = py; //表示px和py不是一伙的
            else
                union_set(find_set(relation[px]), py); //relation[px]和py是一伙的，将其父亲和py合并
            if(relation[py] == 0)
                relation[py] = px;
            else
                union_set(find_set(relation[py]), px);

            px = find_set(x);
            py = find_set(y);
            if(px == py) // 共同的父亲，则说明时一伙的
            {
                gay = 1;
            }
            //else if(find_set(relation[px]) == py) //和px不是一伙的的父亲和py是一伙的，说明px和py不是一伙的
                //printf("In different gangs.\n");
        }
        printf("Scenario #%d:\n", ++s);
        if(gay)
            printf("Suspicious bugs found!\n");
        else
            printf("No suspicious bugs found!\n");
        printf("\n");
    }
    return 0;
}
