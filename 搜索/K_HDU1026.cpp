#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 105;
int n,m;
char map[maxn][maxn];
int vis[maxn][maxn];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
struct node {
	int x,y;
	int step;
	friend bool operator <(node a,node b) {
		return a.step>b.step;
	}
}start,path[maxn][maxn];
priority_queue<node> q;
int bfs() {
	while(!q.empty()) {
		node now=q.top();
//		path.push_back(now);
		q.pop();
		for(int i=0; i<4; i++) {
			int nx,ny;
			nx=now.x+dx[i];
			ny=now.y+dy[i];
			if(nx<0 || nx>=n || ny<0 || ny>=m || vis[nx][ny]==1
			|| map[nx][ny]=='X')
				continue;
			node next;
			next.x=nx; next.y=ny; next.step=now.step+1;
			if(map[nx][ny]!='.') next.step=next.step+(int)(map[nx][ny]-'0');
//			printf("%d:%d,%d\n", next.step,next.x,next.y);
			path[nx][ny]=now;
			if(nx==n-1 && ny==m-1) return next.step;
			q.push(next);
			vis[nx][ny]=1;
			
		}
	}
	return -1;
}
int main() {
	while(~scanf("%d%d", &n, &m)) {
		memset(vis,0,sizeof(vis));
		for(int i=0; i<n; i++) {
			scanf("%s", map[i]);
		}
		while(!q.empty()) q.pop();
		start.x=0; start.y=0; start.step=0;
		q.push(start);
		vis[start.x][start.y]=1;
		int ans=bfs();
//		for(int i=0; i<n; i++) {
//			for(int j=0; j<m; j++) {
//				printf("(%d,%d)",path[i][j].x,path[i][j].y);
//			}
//			cout<<endl;
//		}
		if(ans==-1) printf("God please help our poor hero.\n");
		else {
			printf("It takes %d seconds to reach the target position, let me show you the way.\n", ans);
			stack<node> s;
			node now;
			now.x=n-1; now.y=m-1; now.step=ans;
			while(!(now.x==0 && now.y==0)) {
				s.push(now);
				now=path[now.x][now.y];
			}
//			printf("(0,0)\n");
			node last;
			last.x=0; last.y=0; last.step=0;
			int cnt=0;
			while(!s.empty()) {
				now=s.top();
				
				printf("%ds:(%d,%d)->(%d,%d)\n", ++cnt, last.x, last.y, now.x, now.y);
				if(now.step!=last.step+1) {
					int t=now.step-last.step-1;
					while(t--) {
						printf("%ds:FIGHT AT (%d,%d)\n",++cnt, now.x, now.y);
					}
				}
				last=now;
				s.pop();
			}
		}
		printf("FINISH\n");
	}
}
