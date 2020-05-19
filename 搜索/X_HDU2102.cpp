#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int n,m,t;
char map[2][12][12];
int vis[2][12][12];
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
	vis[start.z][start.x][start.y]=1;
	while(!q.empty()) {
		node now=q.front(); q.pop();
		if(map[now.z][now.x][now.y]=='P') return now.step;
		for(int i=0; i<4; i++) {
			node next;
			next.x=now.x+dx[i];
			next.y=now.y+dy[i];
			next.z=now.z;
			next.step=now.step+1;
			if(next.x<0 || next.x>=n || next.y<0 || next.y>=m
			|| vis[next.z][next.x][next.y]==1 || map[next.z][next.x][next.y]=='*'
			|| next.step>t)
				continue;
			//廣吭音頁>= 	。。。。。。。 
			if(map[next.z][next.x][next.y]=='#') {
				if(now.z==0) next.z=1;
				else next.z=0;
//				if(map[next.x][next.y][next.z]=='*')
//					continue;
			}
			q.push(next);
			vis[next.z][next.x][next.y]=1;
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
		for(int i=0; i<2; i++) {
			for(int j=0; j<n; j++) {
				scanf("%s", map[i][j]);
			}
		}
		
		for(int i=0; i<2; i++) {
			for(int j=0; j<n; j++) {
				for(int k=0; k<m; k++) {
					if(map[i][j][k]=='#' && map[1^i][j][k]=='#'){
						map[i][j][k]='*';
						map[1^i][j][k]='*';
					}
					else if(map[i][j][k]=='#' && map[1^i][j][k]=='*') {
						map[i][j][k]='*';
					}
				}
			}
		}
		int ans=bfs();
		if(ans==-1) printf("NO\n");
		else printf("YES\n");
	}
}
