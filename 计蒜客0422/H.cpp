#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 25;
struct node {
	int x,y,step;
};
queue<node> q;
int dx[]={1,1,-1,-1,2,2,-2,-2};
int dy[]={2,-2,2,-2,1,-1,1,-1};
int n;
int bfs(node end) {
	while(!q.empty()) {
		node now = q.front(); q.pop();
		for(int i=0; i<8; i++) {
			node next;
			next.x = now.x+dx[i];
			next.y = now.y+dy[i];
			next.step = now.step+1;
			if(next.x<=0||next.x>n||next.y<=0||
			next.y>n)
				continue;
			if(next.x==end.x&&next.y==end.y)
				return next.step;
			q.push(next);
		}
	}
}
int main() {
	int t;
	cin>>t;
	for(int i=1; i<=t; i++) {
		node start,end;
		cin>>n>>start.x>>start.y>>end.x>>end.y;
		start.step=0;
		while(!q.empty()) {
			q.pop();
		}
		q.push(start);
		cout<<"Case #"<<i<<": "<<bfs(end)<<endl;
	}
}
