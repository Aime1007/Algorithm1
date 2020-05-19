#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int m,n;
char map[25][25];
int vis[25][25];
struct node {
	int x,y;
	int step;
	friend bool operator<(node a,node b) {
		return a.step>b.step;
	}
}start;
priority_queue<node> q;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int bfs() {
	while(!q.empty()) {
		node now=q.top();
		q.pop();
		for(int i=0; i<4; i++) {
			int nx,ny,step;
			nx=now.x+dx[i];
			ny=now.y+dy[i];
			step=now.step+1;
			if(nx<0 || nx>=m || ny <0 || ny>=n ||
			map[nx][ny]=='*' || vis[nx][ny]==1)
				continue;
			node next;
			next.x=nx; next.y=ny; next.step=step;
			if(map[nx][ny]=='T') return next.step;
			vis[nx][ny]=1;
			q.push(next);
			
			if(map[nx][ny]=='|') {
				if(now.step%2!=0) {
					if(i==0) {
						step+=1;
						ny=ny+1;
					}
					else if(i==1) {
						step+=1;
						ny=ny-1;
					}
					else if(i==2) {
						nx=nx+1;
					}
					else {
						nx=nx-1;
					}	
								
				}
				else {
					if(i==2) {
						step+=1;
						nx=nx+1;
					}
					else if(i==3) {
						step+=1;
						nx=nx-1;
					}
					else if(i==0) {
						ny=ny+1;
					}
					else {
						ny=ny-1;
					}
				}
				
				next.x=nx; next.y=ny; next.step=step;
				if(map[nx][ny]=='T') return next.step;
				vis[nx][ny]=1;
				q.push(next);
			}
			else if(map[nx][ny]=='-') {
				if(now.step%2!=0) {
					if(i==2) {
						step+=1;
						nx=nx+1;
					}
					else if(i==3) {
						step+=1;
						nx=nx-1;
					}
					else if(i==1) {
						ny=ny+1;
					}
					else {
						ny=ny-1;
					}					
				}
				else {
					if(i==0) {
						step+=1;
						ny=ny+1;
					}
					else if(i==1) {
						step+=1;
						ny=ny-1;
					}
					else if(i==2) {
						nx=nx+1;
					}
					else {
						nx=nx-1;
					}
				}
				
				next.x=nx; next.y=ny; next.step=step;
				if(map[nx][ny]=='T') return next.step;
				vis[nx][ny]=1;
				q.push(next);
			}
			
		}
	}
	return -1;
}
int main() {
	while(cin>>n>>m) {
		memset(vis,0,sizeof(vis));
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				cin>>map[i][j];
				if(map[i][j]=='S') {
					start.x=i;
					start.y=j;
				}
			}
		}
		while(!q.empty()) q.pop();
		vis[start.x][start.y]=1;
		q.push(start);
		int ans=bfs();
		cout << ans <<endl;
	}
}
