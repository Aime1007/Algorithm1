#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
char a[1005][1005];
int v[1005][1005];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int n, m;
struct Node {
	int x,y;
};
queue<Node> q;
void bfs() {
	while(q.size()) {
		Node now = q.front(); q.pop();
		for(int i=0; i<4; i++) {
			Node next;
			next.x = now.x+dx[i];
			next.y = now.y+dy[i];
			if(next.x<1 || next.x>n || next.y<1 || next.y>m) continue;
			if(v[next.x][next.y]==-1) {
				v[next.x][next.y]=v[now.x][now.y]+1;
				q.push(next);
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> a[i]+1 ;
	memset(v, -1, sizeof(v));
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(a[i][j]=='1') {
				Node node;
				node.x=i; node.y=j;
				q.push(node);
				v[i][j]=0;
			}
		}
	}
	bfs();
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cout << v[i][j] <<" ";
		}
		cout <<endl;
	}
}
