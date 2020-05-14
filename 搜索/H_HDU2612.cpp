#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n,m;
char map[205][205];
int vis[205][205];
int kfc[205][205];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
struct node {
	int x,y;
	int step;
}yy,mm;
queue<node> q;
void bfs() {
	while(!q.empty()) {
		node now=q.front();
		q.pop();
		for(int i=0; i<4; i++) {
			int nx,ny;
			nx=now.x+dx[i];
			ny=now.y+dy[i];
			if(nx<0 || nx>=n || ny<0 || ny>=m ||
			vis[nx][ny]==1 || map[nx][ny]=='#')
				continue;
			
			node next;
			next.x=nx; next.y=ny; next.step=now.step+11;
			vis[nx][ny]=1;
			if(map[nx][ny]=='@') {
				kfc[nx][ny]+=next.step;
			}
			q.push(next);
		}
	}
}
int main() {
	while(cin>>n>>m) {
		memset(vis,0,sizeof(vis));
		memset(kfc,0,sizeof(kfc));
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				cin>>map[i][j];
				if(map[i][j]=='Y') {
					yy.x=i;
					yy.y=j;
					yy.step=0;
				}
				if(map[i][j]=='M') {
					mm.x=i;
					mm.y=j;
					mm.step=0;
				}
			}
		}
		while(!q.empty()) q.pop();
		q.push(yy);
		vis[yy.x][yy.y]=1;
		bfs();
		while(!q.empty()) q.pop();
		memset(vis,0,sizeof(vis));
		q.push(mm);
		vis[mm.x][mm.y]=1;
		bfs();
		int ans=INT_MAX;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(kfc[i][j]<ans && kfc[i][j]) {
					ans=kfc[i][j];
				}
			}
		}
		cout<< ans <<endl;
	}
}
