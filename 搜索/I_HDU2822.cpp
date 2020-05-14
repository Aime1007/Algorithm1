#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int n,m;
char map[1005][1005];
int vis[1005][1005];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
struct node {
	int x,y;
	int step;
	friend bool operator < (node a,node b) {
		return a.step>b.step;
	}
}start,final;
priority_queue<node> q;
int bfs() {
	while(!q.empty()) {
		node now=q.top();
		q.pop();
		if(now.x==final.x && now.y==final.y) return now.step;
		for(int i=0; i<4; i++) {
			int nx,ny;
			nx=now.x+dx[i];
			ny=now.y+dy[i];
			if(nx<1 || nx>n || ny<1 || ny>m || vis[nx][ny]==1)
				continue;
			node next;
			next.x=nx; next.y=ny; next.step=now.step;
			if(map[nx][ny]=='.') {
				next.step+=1;
			}
			q.push(next);
			vis[nx][ny]=1;
		}
	}
}
int main() {
	while(~scanf("%d%d", &n, &m)) {
		if(n==0 && m==0) break; 
		memset(vis,0,sizeof(vis));
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				cin>>map[i][j];
			}
		}
		scanf("%d%d", &start.x, &start.y);
		scanf("%d%d", &final.x, &final.y);
		start.step=0;
		while(!q.empty()) q.pop();
		q.push(start);
		vis[start.x][start.y]=1;
		int ans=bfs();
		printf("%d\n", ans);
	}
}
