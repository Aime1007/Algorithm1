#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int n,m,t;
char map[22][22];
int vis[22][22][(1<<10)+5];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
struct node {
	int x,y,z;
	int step;
}start;
queue<node> q;
int bfs() {
	while(!q.empty()) {
		node now=q.front(); q.pop();
		if(map[now.x][now.y]=='^') return now.step;
		for(int i=0; i<4; i++) {
			node next;
			next.x=now.x+dx[i];
			next.y=now.y+dy[i];
			next.z=now.z;
			next.step=now.step+1;
			if(next.x<0 || next.x>=n || next.y<0 || next.y>=m
			|| map[next.x][next.y]=='*' || next.step>=t) continue;
			
			if(map[next.x][next.y]=='.') {
				if(!vis[next.x][next.y][next.z]) {
					q.push(next);
					vis[next.x][next.y][next.z]=1;					
				}

			}
			else if(map[next.x][next.y]>='a' && map[next.x][next.y]<='j'){
				int index=(int)(map[next.x][next.y])-(int)('a');
//				next.z=next.z+(1<<index);
				next.z=next.z|1<<index;
				if(!vis[next.x][next.y][next.z]) {
					vis[next.x][next.y][next.z]=1;
					q.push(next);					
				}

			}
			else if(map[next.x][next.y]>='A' && map[next.x][next.y]<='J'){
				int index=(int)(map[next.x][next.y])-(int)('A');
//				if((next.z>>index&1)==1) {
//					q.push(next);
//					vis[next.x][next.y][next.z]=1;
//				}
				if((next.z&1<<index) && !vis[next.x][next.y][next.z]) {
					q.push(next);
					vis[next.x][next.y][next.z]=1;
				}
			}
		}
	}
	return -1;
}
int main() {
	while(~scanf("%d%d%d", &n, &m, &t)) {
		memset(vis,0,sizeof(vis));
		for(int i=0; i<n; i++) {
			scanf("%s", map[i]);
		}
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(map[i][j]=='@') {
					start.x=i;
					start.y=j;
					start.z=0;
					start.step=0;
					vis[i][j][0]=1;
					map[i][j]='.';
					break;
				}
			}
		}
//		for(int i=0; i<n; i++) {
//			for(int j=0; j<m; j++) {
//				printf("%c",map[i][j]);
//			}
//			printf("\n");
//		}
		while(!q.empty()) q.pop();
		q.push(start);
		int ans=bfs();
		cout<<ans<<endl;
	}
}
