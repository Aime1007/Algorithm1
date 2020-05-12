#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
char map[15][15][15];
int vis[15][15][15];
int dx[]={0,0,1,-1,0,0};
int dy[]={0,0,0,0,1,-1};
int dz[]={1,-1,0,0,0,0};
int n;
struct node {
	int x,y,z;
	int step;
}start,final;

int bfs() {
	if(start.x==final.x && start.y==final.y) return 0;
	queue<node> q;
	q.push(start);
	while(!q.empty()) {
		node now=q.front();
		q.pop();
		for(int i=0; i<6; i++) {
			int nx,ny,nz;
			nx=now.x+dx[i];
			ny=now.y+dy[i];
			nz=now.z+dz[i];
			if(nx<0 || nx>=n || ny<0 || ny>=n || nz<0 || nz>=n ||
			vis[nx][ny][nz]==1 || map[nx][ny][nz]=='X')
				continue;
			node next;
			next.x=nx; next.y=ny; next.z=nz; next.step=now.step+1;
			if(next.x==final.x && next.y==final.y && next.z==final.z)
				return next.step;
			vis[nx][ny][nz]=1;
			q.push(next);
		}
	}
	return -1;
}
int main() {
	string s1,s2;
	while(cin>>s1) {
		memset(vis,0,sizeof(vis));
		cin>>n;
		for(int k=0; k<n; k++) {
			for(int i=0; i<n; i++) {
				for(int j=0; j<n; j++) {
					cin>>map[i][j][k];
				}
			}
		}
		cin>>start.x>>start.y>>start.z;
		cin>>final.x>>final.y>>final.z;
		cin>>s2;
		vis[start.x][start.y][start.z]=1;
		int ans=bfs();
		if(ans==-1) cout<<"NO ROUTE"<<endl;
		else cout<< n <<" "<<ans <<endl;
	}
}
