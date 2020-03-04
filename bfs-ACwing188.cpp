#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int c, r;
char map[155][155];
int v[155][155];
struct Node {
	int x,y;
	int step;
}st,ed;
queue<Node> q;
int dx[]={1,1,-1,-1,2,2,-2,-2};
int dy[]={2,-2,2,-2,1,-1,1,-1};
int bfs() {
	while(!q.empty()) {
		Node now = q.front(); q.pop();
		for(int i=0; i<8; i++) {
			Node next;
			next.x = now.x+dx[i];
			next.y = now.y+dy[i];
			next.step = now.step+1;
			if(next.x<0 || next.x>=r || next.y<0 || next.y>=c 
			|| v[next.x][next.y]==1 || map[next.x][next.y]=='*')
				continue;
			if(map[next.x][next.y]=='H') return next.step;
			q.push(next);
			v[next.x][next.y]=1;
		}
	}
}
int main() {
	cin >> c >> r;
	memset(v,0,sizeof(v));
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			cin >> map[i][j];
			if(map[i][j]=='K') {
				st.x=i;
				st.y=j;
				st.step=0;
				v[i][j]=1;
			}
		}
	}
	q.push(st);
	cout << bfs();
}
