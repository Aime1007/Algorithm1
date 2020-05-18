#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
int n,m;
int map[10][10];
//int vis[10][10];
struct node {
	int x,y;
	int step;
	int gg;
}start,final,fa[10][10];

queue<node> q;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int bfs() {
	while(!q.empty()) {
		node now=q.front();
		q.pop();
		if(map[now.x][now.y]==3) return now.step;
		for(int i=0; i<4; i++) {
			int nx,ny,step,gg;
			nx=now.x+dx[i];
			ny=now.y+dy[i];
			step=now.step+1;
			gg=now.gg+1;
			if(nx<0 || nx>=n || ny<0 || ny>=m ||
//			vis[nx][ny]==1 
			 map[nx][ny]==0 || gg>=6)
				continue;
			if(map[nx][ny]==4) {
				gg=0;
				map[nx][ny]=0;
			}
			node next;
			next.x=nx; next.y=ny; next.step=step; next.gg=gg;
//			vis[nx][ny]=1;
			q.push(next);
			fa[nx][ny]=now;
		}
	}
	return -1;
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
//		memset(vis,0,sizeof(vis));
		memset(fa,-1,sizeof(fa));
		scanf("%d%d", &n, &m);
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				scanf("%d", &map[i][j]);
				if(map[i][j]==2) {
					start.x=i;
					start.y=j;
					start.step=0;
					start.gg=0;
				}
				if(map[i][j]==3) {
					final.x=i;
					final.y=j;
				}
			}
		}
		while(!q.empty()) q.pop();
//		vis[start.x][start.y]=1;
		q.push(start);
		int ans=bfs();
		printf("%d\n", ans);
		
//		for(int i=0; i<n; i++) {
//			for(int j=0; j<m; j++) {
//				printf("(%d,%d) ", fa[i][j].x,fa[i][j].y);
//			}
//			cout<<endl;
//		}
//		node now=final;
//		stack<node> s;
//		while(map[now.x][now.y]!=2) {
//			s.push(now);
//			now=fa[now.x][now.y];
//		}
//		
//		while(!s.empty()) {
//			now=s.top(); s.pop();
//			printf("(%d,%d)\n",now.x,now.y);
//		}
	}
}
