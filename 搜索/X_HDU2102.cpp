#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int n,m,t;
char map[12][12][2];
int vis[12][12][2];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
struct node {
	int x,y,z;
	int step;
}start;
int bfs() {
	queue<node> q;
	start.x=0; start.y=0; start.z=0; start.step=0;
	q.push(start);
	vis[start.x][start.y][start.z]=1;
	while(!q.empty()) {
		node now=q.front(); q.pop();
		if(map[now.x][now.y][now.z]=='P') return now.step;
		for(int i=0; i<4; i++) {
			node next;
			next.x=now.x+dx[i];
			next.y=now.y+dy[i];
			next.z=now.z;
			next.step=now.step+1;
			if(map[next.x][next.y][next.z]=='#') {
				if(now.z==0) next.z=1;
				else next.z=0;
				if(map[next.x][next.y][next.z]=='*') continue;
			}
			if(next.x<0 || next.x>=n || next.y<0 || next.y>=m
			|| vis[next.x][next.y][next.z]==1 || map[next.x][next.y][next.z]=='*'
			|| next.step>=14)
				continue;
			q.push(next);
			vis[next.x][next.y][next.z]=1;
		}
	}
	return -1;
}
int main() {
	int c;
	scanf("%d", &c);
	while(c--) {
		scanf("%d%d%d", &n, &m, &t);
		memset(vis,0,sizeof(vis));
		for(int i=0; i<n; i++) {
			scanf("%s", map[i][0]);
		}
		for(int i=0; i<n; i++) {
			scanf("%s", map[i][1]);
		}
		int ans=bfs();
		if(ans==-1) printf("NO\n");
		else printf("YES\n");
	}
}
