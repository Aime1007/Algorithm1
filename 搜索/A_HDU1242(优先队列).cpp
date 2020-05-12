#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 205;
char map[maxn][maxn];
bool vis[maxn][maxn];
int n,m;
struct node {
	int x,y;
	int step;
	friend bool operator<(node a, node b) {
		return a.step > b.step;
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
			int nx,ny;
			nx=now.x+dx[i];
			ny=now.y+dy[i];
			if(nx<1 || nx>n || ny<1 || ny>m || 
			vis[nx][ny]==true || map[nx][ny]=='#')
				continue;
			node next;
			next.x=nx; next.y=ny; next.step=now.step+1;
			vis[nx][ny]=true;
			if(map[nx][ny]=='x') next.step+=1;
			if(map[nx][ny]=='r') {
				return next.step;
			}
			q.push(next);
		}		
	}
	return -1;
}
int main() {
	while(cin>>n>>m) {
		memset(vis,0,sizeof(vis));
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				cin>>map[i][j];
				if(map[i][j]=='a') {
					start.x=i;
					start.y=j;
					start.step=0;
					vis[i][j]=true;
				}
			}
		}
		while(!q.empty()) {
			q.pop();
		}
		q.push(start);
		int ans=bfs();
		if(ans==-1) cout <<"Poor ANGEL has to stay in the prison all his life."<<endl;
		else cout << ans <<endl;		
	}

}
