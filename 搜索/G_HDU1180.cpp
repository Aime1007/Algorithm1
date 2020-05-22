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
}start;
queue<node> q;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
bool judge(node a,int i) {
	if((map[a.x][a.y]=='|' && i%2==1 && (a.step-1)%2==0)
	|| (map[a.x][a.y]=='|' && i%2==0 && (a.step-1)%2==1)
	|| (map[a.x][a.y]=='-' && i%2==0 && (a.step-1)%2==0)
	|| (map[a.x][a.y]=='-' && i%2==1 && (a.step-1)%2==1))
		return true;
	return false;
}
int bfs() {
	while(!q.empty()) {
		node now=q.front();
		q.pop();
		for(int i=0; i<4; i++) {
			node next;
			next.x=now.x+dx[i];
			next.y=now.y+dy[i];
			next.step=now.step+1;
			if(next.x<0 || next.x>=m || next.y <0 || next.y>=n ||
			map[next.x][next.y]=='*' || vis[next.x][next.y]==1)
				continue;
			if(map[next.x][next.y]=='T') return next.step;
			if(map[next.x][next.y]=='.') {
				vis[next.x][next.y]=1;
				q.push(next);
			}
			if(map[next.x][next.y]=='|' || map[next.x][next.y]=='-') {
				if(judge(next,i)) {
					next.x=next.x+dx[i];
					next.y=next.y+dy[i];
					if(next.x<0 || next.x>=m || next.y <0 || next.y>=n ||
					map[next.x][next.y]=='*' || vis[next.x][next.y]==1)
						continue;
					if(map[next.x][next.y]=='T') return next.step;
					vis[next.x][next.y]=true;
					q.push(next);
				}
				else {
					next=now;
					next.step++;
					q.push(next);
				}
			}
			
		}
	}
	return 0;
}
int main() {
	while(cin>>m>>n) {
		memset(vis,0,sizeof(vis));
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				cin>>map[i][j];
				if(map[i][j]=='S') {
					start.x=i;
					start.y=j;
					start.step=0;
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
