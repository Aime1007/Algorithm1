#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
#include <cstdio>
using namespace std;
int a,b,c;
bool vis[105][105];
int mark[105][105];
struct node {
	int x,y;
	int step;
}fa[105][105];
node bfs() {
	queue<node> q;
	node start;
	start.x=start.y=start.step=0;
	q.push(start);
	vis[0][0]=true;
	while(!q.empty()) {
		node now=q.front(); q.pop();
		if(now.x==c || now.y==c) return now;
		for(int i=0; i<6; i++) {
			node next;
			if(i==0) {
				next.x=a;
				next.y=now.y;
				if(!vis[next.x][next.y]) {
					vis[next.x][next.y]=true;
					next.step=now.step+1;
					fa[next.x][next.y]=now;
					mark[next.x][next.y]=i;
					q.push(next);
				}
			}
			else if(i==1) {
				next.x=now.x;
				next.y=b;
				if(!vis[next.x][next.y]) {
					vis[next.x][next.y]=true;
					next.step=now.step+1;
					fa[next.x][next.y]=now;
					mark[next.x][next.y]=i;
					q.push(next);
				}
			}
			else if(i==2) {
				next.x=0;
				next.y=now.y;
				if(!vis[next.x][next.y]) {
					vis[next.x][next.y]=true;
					next.step=now.step+1;
					fa[next.x][next.y]=now;
					mark[next.x][next.y]=i;
					q.push(next);
				}
			}
			else if(i==3) {
				next.x=now.x;
				next.y=0;
				if(!vis[next.x][next.y]) {
					vis[next.x][next.y]=true;
					next.step=now.step+1;
					fa[next.x][next.y]=now;
					mark[next.x][next.y]=i;
					q.push(next);
				}
			}
			else if(i==4) {
				if(now.x>0 && now.y<b) {
					if(now.x<=b-now.y) {
						next.y=now.y+now.x;
						next.x=0;
					}
					else {
						next.y=b;
						next.x=now.x-(b-now.y);
					}
					if(!vis[next.x][next.y]) {
						vis[next.x][next.y]=true;
						next.step=now.step+1;
						fa[next.x][next.y]=now;
						mark[next.x][next.y]=i;
						q.push(next);
					}
				}
			}
			else if(i==5) {
				if(now.y>0 && now.x<a) {
					if(now.y<=a-now.x) {
						next.x=now.x+now.y;
						next.y=0;
					}
					else {
						next.x=a;
						next.y=now.y-(a-now.x);
					}
					if(!vis[next.x][next.y]) {
						vis[next.x][next.y]=true;
						next.step=now.step+1;
						fa[next.x][next.y]=now;
						mark[next.x][next.y]=i;
						q.push(next);
					}
				}
			}
		}
	}
	node final;
	final.x=final.y=final.step=-1;
	return final;
}
void print(node now) {
	if(mark[now.x][now.y]==0) {
		printf("FILL(1)\n");
	}
	else if(mark[now.x][now.y]==1) {
		printf("FILL(2)\n");
	}
	else if(mark[now.x][now.y]==2) {
		printf("DROP(1)\n");
	}
	else if(mark[now.x][now.y]==3) {
		printf("DROP(2)\n");
	}
	else if(mark[now.x][now.y]==4) {
		printf("POUR(1,2)\n");
	}
	else if(mark[now.x][now.y]==5) {
		printf("POUR(2,1)\n");
	}
}
int main() {
	scanf("%d%d%d", &a, &b, &c);
	memset(fa,-1,sizeof(fa));
	node ans=bfs();
	if(ans.step==-1) printf("impossible\n");
	else {
		printf("%d\n", ans.step);
		stack<node> s;
		node now=ans;
		while(!(now.x==0 && now.y==0)) {
			s.push(now);
			now=fa[now.x][now.y];
		}
		while(!s.empty()) {
			now=s.top(); s.pop();
			print(now);
		}
	}
}
