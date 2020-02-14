#include <iostream>
#include <queue>
using namespace std;
const int maxn = 25;
int w;
int h;
char G[maxn][maxn];
int ans=0;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void dfs(int x, int y) {
	G[x][y]='#';
	ans++;
	for(int i=0; i<4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >=0 && nx<w && ny >=0 && ny <h && G[nx][ny]=='.') {
			dfs(nx, ny);
		}
	}
} 
int main() {
	while(cin >>w >>h) {
		ans = 0;
		int x, y;
		if(w==0 && h==0) break;
		for(int j=0; j<h; j++) {
			for(int i=0; i<w; i++) {
				cin >> G[i][j];
				if(G[i][j]=='@') {
					x=i;
					y=j;
				}
			}
		}
		dfs(x, y);
		cout << ans <<endl;
		
	}
}
