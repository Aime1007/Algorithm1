#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int a,b,c,t;
int map[55][55][55];
int vis[55][55][55];
int dx[]={0,0,1,-1,0,0};
int dy[]={0,0,0,0,1,-1};
int dz[]={1,-1,0,0,0,0};
struct node {
	int x,y,z;
	int step;
};
queue<node> q;
int bfs() {
	while(!q.empty()) {
		node now=q.front();
		q.pop();
		for(int i=0; i<6; i++) {
			int nx,ny,nz;
			nx=now.x+dx[i];
			ny=now.y+dy[i];
			nz=now.z+dz[i];
			if(nx<0 || nx>=b || ny<0 || ny>=c || nz<0 || nz>=a ||
			vis[nx][ny][nz]==1 || map[nx][ny][nz]==1)
				continue;
			node next;
			next.x=nx; next.y=ny; next.z=nz; next.step=now.step+1;
			if(next.step>t) return -1;
			if(nx==b-1 && ny==c-1 && nz==a-1) return next.step;
			vis[nx][ny][nz]=1;
			q.push(next);
		}
	} 
	return -1;
}
int main() {
	int k;
	scanf("%d", &k);
	while(k--) {
		memset(vis,0,sizeof(vis));
		scanf("%d%d%d%d", &a, &b, &c, &t);
		for(int z=0; z<a; z++) {
			for(int x=0; x<b; x++) {
				for(int y=0; y<c; y++) {
					scanf("%d", &map[x][y][z]);
				}
			}
		}
		while(!q.empty()) {
			q.pop();
		}
		node start;
		start.x=0; start.y=0; start.z=0; start.step=0;
		vis[0][0][0]=1;
		q.push(start);
		int ans=bfs();
		printf("%d\n", ans);
	}
}
