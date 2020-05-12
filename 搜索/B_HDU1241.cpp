#include <iostream>
using namespace std;
const int maxn = 105;
int n,m;
char map[maxn][maxn];
void dfs(int x,int y) {
	map[x][y]='*';
	for(int dx=-1; dx<=1; dx++) {
		for(int dy=-1; dy<=1; dy++) {
			int nx,ny;
			nx=x+dx;
			ny=y+dy;
			if(nx>=0 && nx<m && ny>=0 && ny<n && map[nx][ny]=='@') 
				dfs(nx,ny);
		}
	}
	return;
}
int main() {
	while(cin>>m>>n) {
		if(m==0) break;
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				cin>>map[i][j];
			}
		}
		int ans=0;
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				if(map[i][j]=='@') {
					dfs(i,j);
					ans++;
				}
			}
		}
		cout << ans <<endl;
	}
}
