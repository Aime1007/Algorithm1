#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
const int maxn=1e5+5;
int h,n,m;
int vis[maxn];
queue<int> q;
bool bfs() {
	vis[h]=1;
	while(!q.empty()) {
		int now=q.front(); q.pop();
		if(now==0) return true;
		int next;
		for(int i=0; i<2; i++) {
			if(i==0) {
				if(n<=0) continue;
				if((now/2+10)<now){
					next=now/2+10;
					n--;
				}
			}
			else if(i==1) {
				if(m<=0) continue;
				if(now-10>=0) {
					next=now-10;
					m--;
				}
				else {
					next=0;
					m--;
				}
			}
			if(n==0 && m==0) continue;
			if(vis[next]==1) 
				continue;
			vis[next]=1;
			q.push(next);
		}
	}
	return false;
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		memset(vis,0,sizeof(vis));
		cin>>h>>n>>m;
		while(!q.empty()) q.pop();
		q.push(h);
		if(bfs()) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}

