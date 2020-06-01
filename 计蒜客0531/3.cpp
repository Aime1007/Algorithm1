#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
int c,d;
char map[55];
int vis[55];
struct node {
	int x,step;
};
bool operator <(node a,node b) {
	return a.step>b.step;
}
int bfs() {
	priority_queue<node> q;
	node start;
	start.x=start.step=0;
	q.push(start);
	vis[start.x]=1;
	while(!q.empty()) {
		node now=q.top(); q.pop();
		if(now.x==c-1) return now.step;
		for(int i=d+1; i>=1; i--) {
			node next;
			next.x=now.x+i;
			next.step=now.step+1;
			if(map[next.x]=='X' || next.x>c-1) continue;
			q.push(next);
			vis[next.x]=1;
		}
	}
	return 0;
}
int main() {
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		memset(vis,0,sizeof(vis));
		
		scanf("%d%d", &c, &d);
		scanf("%s", map);
		printf("Day #%d\n", i);
		printf("%d %d\n", c, d);
		for(int i=0; i<c; i++) printf("%c",map[i]);
		printf("\n");
		printf("%d\n\n", bfs());
	}
}
