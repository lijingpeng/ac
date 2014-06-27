#include <stdio.h>
#include <math.h>
#define MAXN 1010

int n, rank[MAXN], father[MAXN], repaired[MAXN];
struct Pos {
    int x, y;
} pos[MAXN];
void make_set()
{
    for (int i = 1; i <= n; ++i)
        rank[i] = 0, father[i] = i;
}
int find_set(int x)
{
    if (x != father[x])
        father[x] = find_set(father[x]);
    return father[x];
}
void union_set(int x, int y)
{
    x = find_set(father[x]);
    y = find_set(father[y]); // 多向上找一层
    if (x != y)
    {
         if (rank[x] < rank[y])
            father[x] = y;
        else
        {
            father[y] = x;
            if (rank[x] == rank[y])
                ++rank[x];
        }
    }
}
double distance(int a, int b) // 注意标号转换一下
{
    Pos x, y;
    x = pos[a];
    y = pos[b];
    return sqrt(1.0*(x.x-y.x)*(x.x-y.x) + 1.0*(x.y-y.y)*(x.y-y.y));
}
int main()
{
    char c;
    int i, x, y, cnt;
    double d;
    scanf("%d%lf", &n, &d);
    for (i = 1; i <= n; ++i) // 编号1到n..
        scanf("%d%d", &pos[i].x, &pos[i].y);
    cnt = 0;
    make_set();
    while (scanf(" %c%d", &c, &x) != EOF)
        if (c == 'O')
        {
            for (i = 0; i < cnt; ++i) // 与已修好的电脑合并
                if (distance(repaired[i], x) <= d)
                    union_set(repaired[i], x);
            repaired[cnt++] = x; // 加入修好的集合中，逻辑其实恰好相反，是先修再合并
        }
        else
        {
             scanf("%d", &y);
             if (find_set(x) == find_set(y)) // 判断连通性
                 printf("SUCCESS\n");
             else
                 printf("FAIL\n");
        }
    return 0;
}
