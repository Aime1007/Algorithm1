#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 30005;
int n,m;
int fa[maxn];
int size[maxn];
void init() {
	for(int i=0; i<n; i++) {
		fa[i]=i;
		size[i]=1;
	}
}
int get(int x) {
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y) {
	x=get(x);
	y=get(y);
	if(x!=y) {
		fa[x]=y;
		size[y]+=size[x];
	}
}
int main() {
	while(~scanf("%d%d", &n, &m)) {
		if(n==0 && m==0) break;
		init();
		for(int i=1; i<=m; i++) {
			int k,x,y;
			scanf("%d", &k);
			scanf("%d", &x);
			k--;
			for(int j=1; j<=k; j++) {
				scanf("%d", &y);
				merge(x,y);
			}
		}
		printf("%d\n",size[get(0)]);
	}
} 
