#include <iostream>
#include <queue>
using namespace std;
const int maxn = 205;
char map[maxn][maxn];
bool vis[maxn][maxn];
int n,m,ans;
struct node {
	int x,y;
	int step; 
}start,final;
queue<node> q;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void bfs() {
	while(!q.empty()) {
		node now=q.front();
		q.pop();
		for(int i=0; i<4; i++) {
			int nx,ny;
			nx=now.x+dx[i];
			ny=now.y+dy[i];
			if(nx<1 || nx>m || ny<1 || ny>n || 
			vis[nx][ny]==true || map[nx][ny]=='#')
				continue;
			node next;
			next.x=nx; next.y=ny; next.step=now.step+1;
			vis[nx][ny]=true;
			if(map[nx][ny]=='x') next.step+=1;
			if(next.x==final.x && next.y==final.y) {
				ans=next.step;
				break;
			}
			q.push(next);
		}		
	}

}
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin>>map[i][j];
			if(map[i][j]=='r') {
				start.x=i;
				start.y=j;
				start.step=0;
			}
			if(map[i][j]=='a') {
				final.x=i;
				final.y=j;
			}
		}
	}
	while(!q.empty()) {
		q.pop();
	}
	q.push(start);
	bfs();
	cout << ans <<endl;
}
