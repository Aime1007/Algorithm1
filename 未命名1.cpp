#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 10005;
int n,m;
int v[maxn];
int vis[maxn];
struct Node {
	int x;
	int value;
};
queue<Node> q;
void primes() {
	memset(v, 0, sizeof(v));
	for(int i=2; i<10000; i++) {
		if(v[i]) continue;
//		cout << i <<endl;
		for(int j=2; i*j<10000; j++) {
			v[i*j]=1;
		}
	}
}
int bfs() {
	while(!q.empty()) {
		Node now = q.front(); q.pop();
//		cout << now.x <<" "<<now.value<<endl;
		if(now.x==m) return now.value;
		for(int i=1000; i<10000; i++) {
			if(v[i]==1) continue;
			int t=i;
			int tt=now.x;
			int flag=0;
			while(t) {
				int z=t%10;
				int zz=tt%10;
				if(z!=zz) flag++;
				t/=10;
				tt/=10;
			}
			if(flag==1 && vis[i]==0) {
				Node next;
				next.x=i;
				next.value=now.value+1;
				q.push(next);
				vis[next.x]=1;
			}
		}
	}
	return -1;
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		memset(vis,0,sizeof(vis));
		cin >> n >> m;
		if(n>m) swap(n,m);
		primes();
		
		Node start;
		start.x=n;
		start.value=0;
		while(!q.empty()) q.pop();
		q.push(start);
		int ans=bfs();
		if(ans==-1) cout <<"Impossible"<<endl;
		else cout << ans <<endl;
	}
}
