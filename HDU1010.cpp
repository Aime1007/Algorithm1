#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
struct Node {
	int x,y;
	int time;
};
int n,m,t;
char map[10][10];
bool visited[10][10];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
queue<Node> q;

bool bfs() {
	while(!q.empty()) {
		Node p=q.front();
		q.pop();
		for(int i=0; i<4; i++) {
				int nx=p.x+dx[i];
				int ny=p.y+dy[i];
				int nt=p.time+1;
				if( nx<0 || nx>=n || ny<0 || ny>=m || visited[nx][ny]==true || map[nx][ny]=='X') {
					continue;
				}
				else if(map[nx][ny]=='D' && p.time==t) {
					return true;
				}
				if(map[nx][ny]=='.')
					visited[nx][ny]=true;
				
				Node next;
				next.x=nx;
				next.y=ny;
				next.time=nt;
				q.push(next);
		}
	}
	return false;
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
				visited[i][j]=true;
			}
		}
	}
	while(!q.empty()) {
		q.pop();
	}
	q.push(p);
	bool ans=bfs();
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
