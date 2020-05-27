#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=20+10;
char map[maxn][maxn];
int n,m,t;
bool vis[maxn][maxn][(1<<10)+10];
int dx[]= {-1,1,0,0};
int dy[]= {0,0,-1,1};
struct node {
	int x,y,step;
	int key;
} st;
queue<node>q;
bool check(int x,int y) {
	if(x>=0&&x<n&&y>=0&&y<m&&map[x][y]!='*')
		return true;
	return false;
}
int bfs() {
	while(!q.empty())  q.pop();
	memset(vis,false,sizeof(vis));
	vis[st.x][st.y][st.key]=true;
	st.key=st.step=0;
	q.push(st);
	node now,nex;
	while(!q.empty()) {
		now=q.front();
		q.pop();
		if(map[now.x][now.y]=='^')
			return now.step;
		for(int i=0; i<4; i++) {
			nex.x=now.x+dx[i];
			nex.y=now.y+dy[i];
			nex.key=now.key;
			nex.step=now.step+1;
			if(check(nex.x,nex.y) &&nex.step<t ) {
				
		
				if(map[nex.x][nex.y]>='A'&&map[nex.x][nex.y]<='Z') {
					int temp=map[nex.x][nex.y]-'A';
					int nk=now.key&1<<temp;
					if(nk&&!vis[nex.x][nex.y][nex.key]) {
						vis[nex.x][nex.y][nex.key]=true;
						q.push(nex);
					}
				} else if(map[nex.x][nex.y]>='a'&&map[nex.x][nex.y]<='z') {
					int temp=map[nex.x][nex.y]-'a';
					nex.key=now.key|1<<temp;
					if(!vis[nex.x][nex.y][nex.key]) {
						vis[nex.x][nex.y][nex.key]=true;
						q.push(nex);
					}
				} else {
					if(!vis[nex.x][nex.y][nex.key]) {
						vis[nex.x][nex.y][nex.key]=true;
						q.push(nex);
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	while(~scanf("%d%d%d",&n,&m,&t)) {
		for(int i=0; i<n; i++) {
			scanf("%s", map[i]);
			for(int j=0; j<m; j++) {
				if(map[i][j]=='@') {
					st.x=i;
					st.y=j;
					st.key=0;
					st.step=0;
					vis[i][j][0]=1;
					map[i][j]='.';
				}
			}
		}
		int ans=bfs();
		printf("%d\n",ans);
	}
	return 0;
}
