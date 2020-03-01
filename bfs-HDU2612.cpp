#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n, m;
int time;
char map[205][205];
int v[205][205];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
struct Node {
	int x,y;
}yy,mm;
queue<Node> q[2];
bfs(int mark, int start, int end) {
	while(!q[mark].empty()) {
		Node now = q[mark].front();
		for(int i=0; i<4; i++) {
			Node next;
			next.x = now.x+dx[i];
			next.y = now.y+dy[i];
			if(next.x<1 || next.x>n || next.y<1 || next.y>m || map[next.x][next.y]=='#' || v[next.x][next.y]==1)
				continue;
			if(map[next.x][next.y]==end) return true;
			v[next.x][next.y]=1;
			
		}
	}
	return false;
}
int main() {
	while(cin >> n >> m) {	
		for(int i=1; i<=n; i++) {
			scanf("%s", &map[i]+1);
			for(int j=1; j<=m; j++) {
				if(map[i][j]=='Y') yy.x=i, yy.y=j;
				if(map[i][j]=='M') mm.x=i, mm.y=j;
			}
		}
		
		memset(v,0,sizeof(v));
		for(int i=0; i<2; i++) {
			while(!q[i].empty()) q[i].pop();
		}
		q[0].push(yy);
		q[1].push(mm);
		
		while(!q[0].empty() && !q[1].empty()) {
			time++;
	        bool flag1 = bfs(0,'Y','M');
	        bool flag2 = bfs(1,'M','Y');
	        if(flag1 || flag2)
	            cout<<time;
	    }
	}
}
