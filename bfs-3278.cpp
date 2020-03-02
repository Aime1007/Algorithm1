#include <iostream>
#include <queue>
using namespace std;
const int maxn=100005;
int n,k;
int dx[]={-1,1,2};
bool v[maxn];
struct Node {
	int x;
	int time;
};
queue<Node> q;
int bfs() {
	while(!q.empty()) {
		Node now=q.front(); q.pop();
		Node next;
		for(int i=0; i<3; i++) {
			if(i==2) next.x = now.x*dx[i];
			else next.x = now.x+dx[i];
			next.time = now.time+1;
			if(next.x<0 || next.x>=maxn ||v[next.x]==true) continue;
			q.push(next);
			v[next.x]=true;
			if(next.x==k) return next.time;
		}
	}
}
int main() {
	cin >> n >> k;
	Node node;
	node.x=n;
	node.time=0;
	q.push(node);
	if(n==k) cout << 0;
	else cout << bfs();
}
