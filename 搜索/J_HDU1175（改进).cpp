#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 1005;
int n,m,qq;
int map[maxn][maxn];
int vis[maxn][maxn];
int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};

struct node {
	int x,y;
	int cnt;

}start,final;
queue<node> q;
bool bfs() {
	while(!q.empty()) {
		node now=q.front();
		q.pop();
		for(int i=0; i<4; i++) {
			node next;
			next.x=now.x+dx[i];
			next.y=now.y+dy[i];
			
			if(next.x<1 || next.x>n || next.y<1 || next.y>m ||vis[next.x][next.y]==1)
				continue;
			if(next.cnt<=2 && next.x==final.x && next.y==final.y) 
				return true;
			if(map[next.x][next.y]!=0) continue;
			vis[next.x][next.y]=1;
			q.push(next);
		}
	}
	return false;
}
int main() {
	while(~scanf("%d%d", &n, &m)) {
		if(n==0 && m==0) break;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		scanf("%d", &qq);
		for(int i=1; i<=qq; i++) {
			memset(vis,0,sizeof(vis));
			scanf("%d%d%d%d", &start.x, &start.y, &final.x, &final.y);
			if(map[start.x][start.y] != map[final.x][final.y] ||
			map[start.x][start.y]==0 || map[final.x][final.y]==0) {
				printf("NO\n"); continue;
			}
			while(!q.empty()) q.pop();
			vis[start.x][start.y]=1;
			start.cnt=-1;
			q.push(start);
			bool ans=bfs();
			if(ans==true) printf("YES\n");
			else printf("NO\n");
		}
		
	}
}
