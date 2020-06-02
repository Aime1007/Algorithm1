#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
int s,n,m;
bool vis[105][105][105];
struct node {
	int s,a,b;
	int step;
}start;
int bfs() {
	queue<node> q;
	start.s=s; start.a=start.b=start.step=0;
	vis[s][n][m]=true;
	q.push(start);
	while(!q.empty()) {
		node now=q.front(); q.pop();
		if((now.s==now.a && now.s+now.a==s)
		|| (now.s==now.b && now.s+now.b==s))
			return now.step;
		for(int i=0; i<6; i++) {
			node next;
			if(i==0) {
				if(now.a<n && now.s>0) {
					if(now.s<=n-now.a) {
						next.a=now.a+now.s;
						next.b=now.b;
						next.s=0;
					}
					else {
						next.a=n;
						next.b=now.b;
						next.s=now.s-(n-now.a);
					}
					if(!vis[next.s][next.a][next.b]) {
						next.step=now.step+1;
						q.push(next);
						vis[next.s][next.a][next.b]=true;
					}
				}
			}
			else if(i==1) {
				if(now.b<n && now.s>0) {
					if(now.s<=m-now.b) {
						next.b=now.b+now.s;
						next.a=now.a;
						next.s=0;
					}
					else {
						next.b=m;
						next.a=now.a;
						next.s=now.s-(m-now.b);
					}
					if(!vis[next.s][next.a][next.b]) {
						next.step=now.step+1;
						q.push(next);
						vis[next.s][next.a][next.b]=true;
					}
				}
			}
			else if(i==2) {
				if(now.s<s && now.a>0) {
					if(now.a<=s-now.s) {
						next.a=0;
						next.b=now.b;
						next.s=now.s+now.a;
					}
					else {
						next.a=now.a-(s-now.s);
						next.b=now.b;
						next.s=s;
					}
					if(!vis[next.s][next.a][next.b]) {
						next.step=now.step+1;
						q.push(next);
						vis[next.s][next.a][next.b]=true;
					}
				}
			}
			else if(i==3) {
				if(now.s<s && now.b>0) {
					if(now.b<=s-now.s) {
						next.b=0;
						next.a=now.a;
						next.s=now.s+now.b;
					}
					else {
						next.b=now.b-(s-now.s);
						next.a=now.a;
						next.s=s;
					}
					if(!vis[next.s][next.a][next.b]) {
						next.step=now.step+1;
						q.push(next);
						vis[next.s][next.a][next.b]=true;
					}
				}
			}
			else if(i==4) {
				if(now.a>0 && now.b<m) {
					if(now.a<=m-now.b) {
						next.a=0;
						next.b=now.b+now.a;
						next.s=now.s;
					}
					else {
						next.a=now.a-(m-now.b);
						next.b=m;
						next.s=now.s;
					}
					if(!vis[next.s][next.a][next.b]) {
						next.step=now.step+1;
						q.push(next);
						vis[next.s][next.a][next.b]=true;
					}
				}
			}
			else if(i==5){
				if(now.b>0 && now.a<n) {
					if(now.b<=n-now.a) {
						next.b=0;
						next.a=now.a+now.b;
						next.s=now.s;
					}
					else {
						next.b=now.b-(n-now.a);
						next.a=n;
						next.s=now.s;
					}
					if(!vis[next.s][next.a][next.b]) {
						next.step=now.step+1;
						q.push(next);
						vis[next.s][next.a][next.b]=true;
					}
				}
			}
		}
	}
	return -1;
}
int main() {
	while(~scanf("%d%d%d", &s, &n, &m)) {
		memset(vis,0,sizeof(vis));
		if(s==0 && n==0 && m==0) break;
		int ans=bfs();
		if(ans==-1) printf("NO\n");
		else printf("%d\n", ans);
	}
}
