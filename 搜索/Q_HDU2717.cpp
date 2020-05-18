#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 1e5+2;
int map[maxn];
int vis[maxn];
struct node {
	int x,step;
}start,final;
int bfs() {
	queue<node> q;
	q.push(start);
	vis[start.x]=1;
	while(!q.empty()) {
		node now=q.front(); q.pop();
		if(now.x==final.x) return now.step;
		for(int i=0; i<3; i++) {
			node next;
			if(i==0) {
				next.x=now.x+1;
			}
			else if(i==1) {
				next.x=now.x-1;
			}
			else {
				next.x=now.x*2;
			}
			if(next.x<1 || next.x>maxn || vis[next.x]==1) continue;
			next.step=now.step+1;
			vis[next.x]=1;
			q.push(next);
		}		
	}
	return -1;
}
int main() {
	for(int i=1; i<=maxn; i++) {
		map[i]=i;
	}
	while(~scanf("%d%d", &start.x, &final.x)) {
		memset(vis,0,sizeof(vis));
		start.step=0;
		printf("%d\n", bfs());
	}
}
