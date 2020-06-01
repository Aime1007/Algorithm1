#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int g,p;
struct node {
	int w,t,l;
	int step,score;
}start,ans[100];
int vis[105][105][105];
int d[3]={3,1,0};
int indexx;
void bfs() {
	queue<node> q;
	start.w=start.t=start.l=start.step=start.score=0;
	q.push(start);
	while(!q.empty()) {
		node now=q.front(); q.pop();
		if(now.step==g && now.score==p) ans[indexx++]=now;
		for(int i=0; i<3; i++) {
			node next;
			if(i==0) {
				next.score=now.score+3;
				next.w=now.w+1;
				next.t=now.t;
				next.l=now.l;
			}
			else if(i==1) {
				next.score=now.score+1;
				next.w=now.w;
				next.t=now.t+1;
				next.l=now.l;
			}
			else {
				next.score=now.score;
				next.w=now.w;
				next.t=now.t;
				next.l=now.l+1;
			}
			next.step=now.step+1;
			if(vis[next.w][next.t][next.l]==1 || next.step>g || next.score>p) continue;
			q.push(next);
			vis[next.w][next.t][next.l]=1;
		}
	}
	
}
int main() {
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		indexx=0;
		memset(vis,0,sizeof(vis));
		memset(ans,0,sizeof(ans));
		
		scanf("%d%d", &g, &p);
		printf("Team #%d\n",i);
		printf("Games: %d\n",g);
		printf("Points: %d\n",p);
		printf("Possible records:\n");
		bfs();
		for(int i=0; i<indexx; i++) {
			printf("%d-%d-%d\n",ans[i].w,ans[i].t,ans[i].l);
		}
		printf("\n");
	}
	return 0;
}
