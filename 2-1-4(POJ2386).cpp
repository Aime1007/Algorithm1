#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN=1000;
char map[MAXN][MAXN];
int n,m;
void dfs(int i, int j) {
	map[i][j]='.';
	for(int x=-1; x<=1; x++) {
		for(int y=-1; y<=1; y++) {
			int xx=i+x;
			int yy=j+y;
			if( xx<0 || xx>=n || yy<0 || yy>=m || map[xx][yy]=='.')
				continue;	
//			if( xx>=0 && xx<n && yy>=0 && yy<m && map[xx][yy]=='W')
			dfs(xx,yy);			
		}
	}
	return ;
}
int main() {
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++) {
		scanf("%s", &map[i]);
	}
	
	int count=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(map[i][j]=='W') {
				dfs(i, j);
				count++;
			}
		}
	}
	printf("%d\n", count);
}

