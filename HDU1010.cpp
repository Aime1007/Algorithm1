#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
struct Node {
	int x,y;
	int time;
};
int n,m,t;
char map[10][10];
int visited[10][10];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int dfs(Node p) {
	for(int i=0; i<4; i++) {
		int nx=p.x+dx[i];
		int ny=p.y+dy[i];
		int nt=p.time+1;
		if( nx>=0 && nx<n && ny>=0 && ny<m && visited[nx][ny]==0 && map[nx][ny]=='.') {
			Node next;
			next.x=nx; next.y=ny; next.time=nt;
			if(dfs(next)) return 1;
			visited[nx][ny]=0;
		}
		if(map[nx][ny]=='D' && t==p.time) {
			return 1;
		}
	}
	return 0;
}
int main() {
while(scanf("%d %d %d", &n, &m, &t)) {
	if(n==0 && m==0 && t==0) break;
	Node p;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> map[i][j];
			if(map[i][j]=='S') {
				p.x=i;
				p.y=j;
				p.time=0;
				visited[i][j]=1;
			}
		}
	}
	
	int ans=dfs(p);
	if(ans) {
		cout <<"YES"<< endl;
	}
	else {
		cout <<"NO"<< endl;
	}
}
}
/*
2 4 7
S..D
....
*/
