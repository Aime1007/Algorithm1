#include <iostream>
using namespace std;
const int maxn = 1e6+5;
int fa[maxn];
void init() {
	for(int i=1; i=n; i++) {
		fa[i]=i;
	}
}
int get(int x) {
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
void merge(int x, int y) {
	fa[get(x)]=get(y);
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n,m
		scanf("%d%d", &n, &m);
		init();
		for(int i=1; i<=m; i++) {
			
		}
	}
}
