#include <iostream>
using namespace std;
const int maxn =200005;
int n,m,ans;
int fa[maxn];
int d[maxn];
void init() {
	for(int i=1; i<=n+1; i++) {
		fa[i]=i;
		d[i]=0;
	}
}
int get(int x) {
	if(x==fa[x]) return x;
	int r=get(fa[x]);
	d[x]+=d[fa[x]];
	return fa[x]=r;
}
void merge(int x,int y,int sum) {
	int rx=get(x);
	int ry=get(y);
	if(rx!=ry) {
		fa[ry]=rx;
		d[ry]=d[x]+sum-d[y];
	}
	else {
		if(sum!=d[y]-d[x]) ans++;
	}
}
int main() {

	while(~scanf("%d%d", &n, &m)) {
		init();
		ans=0;
		for(int i=1; i<=m; i++) {
			int a,b,s;
			scanf("%d%d%d", &a, &b, &s);
			b++;
			merge(a,b,s);
		}
		printf("%d\n", ans);
	}

	
}
