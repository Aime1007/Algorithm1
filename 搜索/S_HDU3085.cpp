#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 805;
int n,m,timee;
char map[maxn][maxn];
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
struct node {
	int x,y;
} mm,gg,z[2];
queue<node> q[2],qq;
bool isOK(node t) {
	if(t.x < 1 || t.x > n || t.y < 1 || t.y > m)
        return false;   // ??
    if(map[t.x][t.y] == 'X')
        return false;   // ?
    for (int i = 0; i < 2; i++) {
        if(2*timee >= abs(t.x-z[i].x) + abs(t.y-z[i].y))
            return false;     // ??????
    }    
    
    return true;
}
bool bfs(int flag, int num, char start, char final) {
	qq=q[flag];
	for(int i=0; i<num; i++) {
		while(!qq.empty()) {
			node now=qq.front();
			qq.pop();
			q[flag].pop();
			if(!isOK(now)) continue;
			//ÂèµÄ£¬¾øÁË£¡ 
			for(int i=0; i<4; i++) {
				node next;
				next.x=now.x+dx[i];
				next.y=now.y+dy[i];
				if(!isOK(next) || map[next.x][next.y]==start)
					continue;
				if(map[next.x][next.y]==final) return true;
				map[next.x][next.y]=start;
				q[flag].push(next);
			}
		}
		qq=q[flag];
	}
	return false;
}
int solve() {
	timee=0;
	while(!q[0].empty()) q[0].pop();
	while(!q[1].empty()) q[1].pop();
	while(!qq.empty()) qq.pop();
	q[0].push(mm);
	q[1].push(gg);
	while(!q[0].empty() && !q[1].empty()) {
		timee++;
		bool flag1=bfs(0,3,'M','G');
		bool flag2=bfs(1,1,'G','M');
		if(flag1 || flag2) return timee;
	}
	return -1;
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		memset(map,'X',sizeof(map));
		for(int i=1; i<=n; i++) {
			scanf("%s", map[i]+1);
		}
		int flag=0;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				if(map[i][j]=='M') {
					mm.x=i;
					mm.y=j;
				}
				if(map[i][j]=='G') {
					gg.x=i;
					gg.y=j;
				}
				if(map[i][j]=='Z') {
					z[flag].x=i;
					z[flag].y=j;
					flag++;
				}
			}
		}
		printf("%d\n", solve());
	}
}
