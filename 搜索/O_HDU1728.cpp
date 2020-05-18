#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int n,m;
int k,x1,y1,x2,y2;
char map[105][105];
int vis[105][105];
struct node {
	int x,y;
	int cnt;
};
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool bfs() {
	queue<node> q;
	node start;
	start.x=x1; start.y=y1; start.cnt=-1;
	vis[x1][y1]=1;
	q.push(start);
	while(!q.empty()) {
		node now=q.front();
		q.pop();
		if(now.x==x2 && now.y==y2 && now.cnt<=k) return true;
		node next;
		next.cnt=now.cnt+1;
		for(int i=0; i<4; i++) {
			next.x=now.x+dx[i];
			next.y=now.y+dy[i];
			while(next.x>=0 && next.x<n && next.y>=0 && next.y<m
			&& map[next.x][next.y]=='.') {
				if(!vis[next.x][next.y]) {
					q.push(next);
					vis[next.x][next.y]=1;
				}
				next.x+=dx[i];
				next.y+=dy[i];
			}
		}
	}
	return false;
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		memset(vis,0,sizeof(vis));
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; i++) {
			scanf("%s", map[i]);
		}
		//坐标别弄反了 
		scanf("%d%d%d%d%d", &k, &y1, &x1, &y2, &x2);
		x1-=1; y1-=1; x2-=1; y2-=1;
		if(bfs()) printf("yes\n");
		else printf("no\n");
	}
}
