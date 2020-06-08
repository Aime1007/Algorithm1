#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
int t,n,c,m;
char num[20];
bool vis[5005];
struct node {
	int s[505];
	int len;
};
int mod(node a) {
	int temp=0;
	for(int i=0; i<a.len; i++) {
		temp=(temp*c+a.s[i])%n;
	}
	return temp;
} 
void print(node a) {
	for(int i=0; i<a.len; i++) {
		if(a.s[i]<=9) printf("%d", a.s[i]);
		else printf("%c", a.s[i]+'A'-10);
	}
	printf("\n");
}
int bfs() {
	memset(vis,0,sizeof(vis));
	queue<node> q;
	node start;
	start.len=0;
	int r;
	for(int i=1; i<16; i++) {
		if(num[i]) {
			start.s[0]=i;
			start.len=1;
			r=mod(start);
			if(!r) {
				print(start);
				return 1;
			}
			else {
				if(!vis[r]) {
					vis[r]=1;
					q.push(start);
				}
			}
		}
	}
	while(!q.empty()) {
		node now=q.front(); q.pop();
		for(int i=0; i<16; i++) {
			if(num[i]) {
				now.s[now.len]=i;
				now.len++;
				r=mod(now);
				if(r==0) {
					print(start);
					return 1;
				}
				else {
					if(vis[r]==0 && now.len<499) {
						vis[r]=1;
						q.push(now);
					}
				}
				now.len--;
			}
		}
	}
	return 0;
}
int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &c);
		scanf("%d", &m);
		for(int i=0; i<m; i++) {
			scanf("%d", &num[i]);
		}
		
		if(n) {
			int ans;
			ans=bfs();
			if(!ans) printf("give me the bomb please\n");
		}
		else {
			if(num[0]) printf("0\n");
			else printf("give me the bomb please\n");
		}
		
		bfs();
	}
	return 0;
}

