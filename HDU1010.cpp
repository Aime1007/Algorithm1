#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
//struct Node {
//	int x,y;
//	int time;
//};
int n,m,t;
char map[10][10];
int visited[10][10];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

//int dfs(Node p) {
//	for(int i=0; i<4; i++) {
//		int nx=p.x+dx[i];
//		int ny=p.y+dy[i];
//		int nt=p.time+1;
//		cout << nt << endl;
//		if( nx>=0 && nx<n && ny>=0 && ny<m && visited[nx][ny]==0 && map[nx][ny]!='X') {
//			visited[nx][ny]=1;
//			Node next;
//			next.x=nx; next.y=ny; next.time=nt;
//			if(map[nx][ny]=='D' && t==nt) {
//				return 1;
//			}
//			
//			if(dfs(next)) return 1;
//			visited[nx][ny]=0;
//		}
//		else {
//			visited[nx][ny]=0;
//			return 0;
//		}
//	}
//}

int dfs(int x, int y, int time) {
	if(map[x][y]=='D' && time==t) {
		return 1;
	}
	if(time>=t) return 0;
	for(int i=0; i<4; i++) {
		int nx=x+dx[i];
		int ny=y+dy[i];
		if( nx>=0 && nx<n && ny>=0 && ny<m && visited[nx][ny]==0 && map[nx][ny]!='X') {
			visited[nx][ny]=1;
			if(dfs(nx, ny, time+1)) {
				return 1;
			}
			visited[nx][ny]=0;
		}
	}
	return 0;
}
int main() {
while(scanf("%d %d %d", &n, &m, &t)) {
	if(n==0 && m==0 && t==0) break;
	
	memset(visited,0,sizeof(visited));
	int sx, sy, ex, ey;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> map[i][j];
			if(map[i][j]=='S') {
				sx=i;
				sy=j;
				visited[i][j]=1;
			}
			if(map[i][j]=='D') {
				ex=i;
				ey=j;
			}
		}
	}
	
	
	if((abs(ex-sx)+abs(ey-sy))%2!=t%2)
            cout<<"NO"<<endl;
    else {
    	if(dfs(sx, sy, 0)) {
			cout <<"YES"<< endl;
		}
		else {
			cout <<"NO"<< endl;
		}
	}
		
}
}
/*
2 4 7
S..D
....

4 4 5
S.X.
..X.
..XD
....
*/
