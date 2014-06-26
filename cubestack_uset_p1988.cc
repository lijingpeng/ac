#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
const int MAXSIZE = 30005;
typedef struct node{
	int dist;
	int father;
	int nodeNum;
}Cube;
Cube cube[MAXSIZE];
void init(){
  for(int i = 1;i<MAXSIZE;i++){
   cube[i].dist = 0;
   cube[i].father = i;
   cube[i].nodeNum = 1;
  }
}
int find(int x){
	if(cube[x].father!=x){
		int tmp = cube[x].father;
		cube[x].father = find(cube[x].father);
		cube[x].dist = cube[tmp].dist+cube[x].dist;
	}
	return cube[x].father;
}
void Union(int x,int y){
	cube[x].father = y;
	cube[x].dist = cube[y].nodeNum;
	cube[y].nodeNum = cube[y].nodeNum+cube[x].nodeNum;
}
int main(){
	int p;
	scanf("%d",&p);
	getchar();
	init();
	for(int i = 0;i<p;i++){
		int ch = getchar();
		int a,b;
		if(ch =='M'){
			scanf("%d%d",&a,&b);
			int p = find(a);
			int q = find(b);
			if(p!=q){
				Union(p,q);
			}
		}
		else if(ch == 'C'){
			scanf("%d",&a);
			int p = find(a);
			cout<<cube[a].dist<<endl;
		}
		getchar();
	}

	return 0;
}
