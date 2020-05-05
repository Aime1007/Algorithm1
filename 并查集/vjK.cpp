#include <iostream>
using namespace std;
const int maxn = 1e6+5;
int fa[maxn];
int n,m;
void init() {
	for(int i=1; i<=2*n; i++) {
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
bool judge(int x,int y) {
	if(get(x)==get(y)) return true;
	return false;
}
int main() {
	int t,flag=0;
	scanf("%d", &t);
	for(int z=1; z<=t; z++){
		scanf("%d%d", &n, &m);
		init();
		int a,b;
		for(int i=1; i<=m; i++) {
			int x,y;
			scanf("%d%d", &x, &y);
			if(i==1) {
				a=x;
				b=y+n;
				continue;
			}
			
			if(judge(x,y)) {
				flag=1;
				break;
			}
			else {
				if(x<n) {
					merge(a,x);
					merge(b,y+n);
				}
				else {
					merge(a,y);
					merge(b,x+n);
				}
			}
			
		}
		printf("Scenario #%d:\n", z);
		if(flag==1) printf("Suspicious bugs found!\n\n");
		else printf("No suspicious bugs found!\n\n");
	}
}
