#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;
int map[5][5];
int vis[5][5];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
struct node {
	int x,y;
}fa[5][5];
void bfs() {
	queue<node> q;
	node start;
	start.x=0; start.y=0;
	q.push(start);
	vis[start.x][start.y]=1;
	while(!q.empty()) {
		node now=q.front(); q.pop();
		if(now.x==4 && now.y==4) break;
		for(int i=0; i<4; i++) {
			node next;
			next.x=now.x+dx[i];
			next.y=now.y+dy[i];
			if(next.x<0 || next.x>4 || next.y<0 || next.y>4
			|| vis[next.x][next.y]==1 || map[next.x][next.y]==1)
				continue;
			fa[next.x][next.y]=now;
			vis[next.x][next.y]=1;
			q.push(next);
		}
	}
}
int main() {
	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	bfs();
	stack<node> s;
	node now;
	now.x=4; now.y=4;
	while(!(now.x==0 && now.y==0)) {
		s.push(now);
		now=fa[now.x][now.y];
	}
	printf("(0, 0)\n");
	while(!s.empty()) {
		printf("(%d, %d)\n", s.top().x, s.top().y);
		s.pop();
	}
}
