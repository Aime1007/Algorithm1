#include <iostream>
#include <cstdio>
const int maxn = 505;
int n,m;
int fa[maxn];
void init() {
	for(int i=1; i<=3*n; i++) {
		fa[i]=i;
	}
}
int get(int x) {
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}
void merge(int x, int y) {
	fa[get(x)]=get(y);
}
int main() {

	while(~scanf("%d%d", &n, &m)) {
		for(int i=1; i<=m; i++) {
			int x,y;
			char ch[3];
			scanf("%d%c%d", &x, &ch[0], &y);
			if(ch[0]=='<') {
				merge(x,y);
			}
		}
	}
}
