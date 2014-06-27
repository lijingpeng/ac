#include<iostream>
#include<cstdio>
using namespace std;
const int N = 105;

int p[N];
bool flag[N];

void make_set(void)
{
    for(int i = 0; i < 105; i++)
    {
        p[i] = i;
        flag[i] = false;
    }
}

int find_set(int x){
    return p[x] == x ? x : (p[x] = find_set(p[x]));
}

void union_set(int x, int y){
    x = find_set(x);
    y = find_set(y);
    if(x == y) return;
    p[y] = x;
}

int main(){
    int x, y, t = 1, first;
    while(scanf("%d %d", &x, &y) != EOF){
        if(x == -1 && y == -1) break;
        if(x == 0 && y == 0){        // 1.空树也是树，果断坑爹了
            printf("Case %d is a tree.\n", t++);
            continue;
        }

        make_set();
        flag[x] = flag[y] = true;
        first = x;
        bool tree = true;
        if(x == y) 
            tree = false;    //  两个数相等表示同一点指向自己，不是树，同第2点
        else
            union_set(x, y);

        while(scanf("%d %d", &x, &y) && x != 0){
            flag[x] = flag[y] = true;
            if(find_set(x) == find_set(y)) tree = false;   // 2.两个数的树根相同
            //但再次将y指向了x，重复指向也不是树
            union_set(x, y);//合并
        }
        for(int i = 1; i < 105; i ++)   //3.最后只能有一个树根，多个树根为森林
            if(flag[i] && find_set(i) != find_set(first)) {
                tree = false;
                break;
            }
        if(tree) 
            printf("Case %d is a tree.\n", t++);
        else
            printf("Case %d is not a tree.\n", t++);
    }
    return 0;
}
