#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
const int MAXN=1000;

//typedef pair<int, int> P;
struct Node {
	int x,y;
	int step;
};
char map[MAXN][MAXN];
int n,m;
int sx,sy; //Æðµã×ø±ê
int gx,gy;
int visited[MAXN][MAXN]; 
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
queue<Node> q;
int bfs() {
	
	while(!q.empty()) {
		Node p = q.front(); q.pop();
		
		if(p.x==gx && p.y==gy) break;
		
		for(int i=0; i<4; i++) {
			int nx = p.x+dx[i], ny = p.y+dy[i], nstep=p.step+1;
			if(nx<0||nx>=n||ny<0||ny>=m||map[nx][ny]=='#'||visited[nx][ny]==1){
                continue;
            }
            Node ptr;
            ptr.x = nx; ptr.y = ny; ptr.step = nstep;
//            if(map[ptr.x][ptr.y]=='x'){
//                ptr.step += 1;
            if(map[ptr.x][ptr.y]=='G'){
                return ptr.step;
            }
            q.push(ptr);
            visited[ptr.x][ptr.y] = 1;
		}
		
	}
}
int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> map[i][j];
			if(map[i][j] == 'S'){
                sx=i;sy=j;
            }
		}
	}
	Node p;
	p.x=sx; p.y=sy; p.step=0;
	visited[sx][sy]=0;
	q.push(p);
	int ans=bfs();
	printf("%d", ans);
}
/*
10 10
#S######.#
......#..#
.#.##.##.#
.#........
##.##.####
....#....#
.#######.#
....#.....
.####.###.
....#...G#
*/
