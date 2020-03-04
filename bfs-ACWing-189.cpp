#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int m, n, stx, sty;
int ans;
char map[105][105];
int v[105][105];
int dx[]={0,0,-1,1,1,1,-1,-1};
int dy[]={-1,1,0,0,1,-1,1,-1};
struct Node {
	int x,y;
	int step;
};
queue<Node> q;
void bfs() {
	while(!q.empty()) {
		Node now = q.front(); q.pop();
		for(int i=0; i<8; i++) {
			Node next;
			next.x = now.x+dx[i];
			next.y = now.y+dy[i];
			next.step = now.step+1;
			if(next.x<1 || next.x>n || next.y<1 || next.y>m 
			|| v[next.x][next.y]==1 || map[next.x][next.y]=='*')
				continue;
			if(next.step>ans) 
			ans = next.step;
			q.push(next);
			v[next.x][next.y]=1;	
//			for(int i=1; i<=n; i++) {
//				for(int j=1; j<=m; j++) {
//					cout << v[i][j];
//				}
//				cout<<endl;
//			}	
//			cout<<endl;				
		}
	}
}
int main() {
	cin >> m >> n >> sty >> stx;
	memset(v,0,sizeof(v));
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin >> map[i][j];
		}
	}
	
	Node start;
	start.x=n-stx+1; start.y=sty; start.step=0;
	ans=start.step;
	q.push(start);
	v[start.x][start.y]=1;
	bfs();
	cout << ans;
}
