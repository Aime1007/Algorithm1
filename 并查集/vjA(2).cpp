#include <iostream>
using namespace std;
const int MAXN = 1005;
//int t,n,m; 放这WA 
int root[MAXN];
int h[MAXN];
void init() {
	for(int i=1; i<=MAXN; i++) {
		root[i]=i;
		h[i]=0;
	}
}
int get(int x) {
	if(x==root[x]) return x;
	return root[x]=get(root[x]);
}
void merge(int x,int y) {
	x=get(x);
	y=get(y);
	if(h[x]==h[y]) {
		h[x]=h[x]+1;
		root[y]=x;
	}
	else {
		if(h[x]<h[y]) root[x]=y;
		else root[y]=x;
	}
}
int main() {
	int t,n,m; //一定放在这 
	cin>>t;
	while(t--) {
		cin>>n>>m;
		init();
		for(int i=1; i<=m; i++) {
			int a,b;
			cin>>a>>b;
			merge(a,b);
		}
		int ans=0;
		for(int i=1; i<=n; i++) {
			if(root[i]==i) ans++;
		}
		cout << ans <<endl;
	}

}
