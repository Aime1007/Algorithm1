#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 2e5+10;
int t,n,m;
int fa[maxn];
void init() {
	for(int i=1; i<=2*n; i++) {
		fa[i]=i;
	}
}
int get(int x) {
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y) {
	fa[get(x)]=get(y);
}
bool judge(int x,int y) {
	if(get(x)==get(y)) return true;
	return false;
}
int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		init();
		for(int i=1; i<=m; i++) {
			int a,b;
			char ch;
			getchar();
			scanf("%c%d%d", &ch, &a, &b);
			if(ch=='D') {
				merge(a,b+n);
				merge(a+n,b);
			}
			else {
				if(judge(a,b) || judge(a+n,b+n)) {
					printf("In the same gang.\n");
				}
				else if(judge(a,b+n) || judge(a+n,b)) {
					printf("In different gangs.\n");
				}
				else {
					printf("Not sure yet.\n");
				}
			}
		}
	}
}
