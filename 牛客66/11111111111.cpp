#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
const int maxn=105;
char map[maxn][maxn];
int vis[maxn][maxn];
int n;
struct node {
	int x,y;
	int cnt;
}start,final;
queue<node> q;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int bfs() {
	while(!q.empty()) {
		node now=q.front(); q.pop();
		if(now.x==final.x && now.y==final.y) return now.cnt;
		node next;
		next.cnt=now.cnt+1;
		for(int i=0; i<4; i++) {
			next.x=now.x+dx[i];
			next.y=now.y+dy[i];
			while(next.x>=0 && next.x<n && next.y>=0 && next.y<n) {
				if(next.x==final.x && next.y==final.y) 
					return now.cnt;
				if(map[next.x][next.y]=='x') break;
				if(!vis[next.x][next.y]) {
					q.push(next);
					vis[next.x][next.y]=1;
				}
				next.x+=dx[i];
				next.y+=dy[i];
			}
		}
	}
	return -1;
}
int main() {
	scanf("%d", &n); 
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin>>map[i][j];
			getchar();
			if(map[i][j]=='A') {
				start.x=i;
				start.y=j;
				start.cnt=0;
			}
			if(map[i][j]=='B') {
				final.x=i;
				final.y=j;
			}
		}
	}
	while(!q.empty()) q.pop();
	q.push(start);
	vis[start.x][start.y]=1;
	printf("%d", bfs());
	return 0;
}

