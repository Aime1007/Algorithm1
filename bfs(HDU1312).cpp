#include <iostream>
#include <queue>
using namespace std;
const int maxn = 25;
int w;
int h;
struct Node {
	int x, y;
};
char G[maxn][maxn];
bool visited[maxn][maxn];
queue<Node> q;
int ans=1;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void bfs() {
	while(!q.empty()) {
		Node now=q.front();
		q.pop();
		for(int i=0; i<4; i++) {
			int nx = now.x+dx[i];
			int ny = now.y+dy[i];
			if(nx>=0 && nx<w && ny>=0 && ny<h && G[nx][ny]=='.' && visited[nx][ny]==false) {
				ans++;
				visited[nx][ny]=true;
				Node next; next.x=nx; next.y=ny;
				q.push(next);
			}	
		}
	}
}
int main() {
	while(cin >>w >>h) {
		ans = 1;
		Node s;
		if(w==0 && h==0) break;
		for(int j=0; j<h; j++) {
			for(int i=0; i<w; i++) {
				cin >> G[i][j];
				visited[i][j]=false;
				if(G[i][j]=='@') {
					s.x=i;
					s.y=j;
					visited[i][j]=true;
				}
			}
		}
		
		q.push(s);
		bfs();
		cout << ans <<endl;
		
	}
}
