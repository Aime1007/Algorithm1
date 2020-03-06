#include <iostream>
#include <cstring>
using namespace std;
int map[10][10];

bool r[10][10];
bool c[10][10];
bool g[10][10];
bool dfs(int x,int y) {
	if(x==10) return true;
	bool flag=false;
	if(map[x][y]) {
		if(y==9) flag=dfs(x+1, 1);
		else flag=dfs(x,y+1);
		
		if(flag) return true;
		else return false;
	}
	else {
		int k=3*((x-1)/3)+(y-1)/3+1;
		for(int i=1; i<=9; i++) {
			if(!r[x][i] && !c[y][i] && !g[k][i]) {
				map[x][y]=i;
				r[x][i]=true;
				c[y][i]=true;
				g[k][i]=true;
				
				if(y==9) flag=dfs(x+1,1);
				else flag=dfs(x,y+1);
				
				if(!flag) {
					map[x][y]=0;
					r[x][i]=false;
					c[y][i]=false;
					g[k][i]=false;
				}
				else return true;
			}
		}
	}
	return false;
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		memset(r,false,sizeof(r));
		memset(c,false,sizeof(c));
		memset(g,false,sizeof(g));
		
		char MAP[10][10];
		for(int i=1; i<=9; i++) {
			for(int j=1; j<=9; j++) {
				cin >> MAP[i][j];
				map[i][j]=MAP[i][j]-'0';
				
				if(map[i][j]) {
					int k=3*((i-1)/3)+(j-1)/3+1;
					r[i][map[i][j]] = true;
					c[j][map[i][j]] = true;
					g[k][map[i][j]] = true;
				}
			}
		}
		
		dfs(1,1);
		for(int i=1; i<=9; i++) {
			for(int j=1; j<=9; j++) {
				cout<<map[i][j];
			}
			cout<<endl;
		}
	}
}
