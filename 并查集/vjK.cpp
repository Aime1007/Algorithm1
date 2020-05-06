#include <iostream>
using namespace std;
const int maxn = 4500;
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
	if(x!=y)
		fa[get(x)]=get(y);
}
bool judge(int x,int y) {
	if(get(x)==get(y)) return true;
	return false;
}

int main() {
	int t;
	scanf("%d", &t);
	for(int z=1; z<=t; z++){
		scanf("%d%d", &n, &m);
		init();
		int flag=0;
		for(int i=1; i<=m; i++) {
			int x,y;
			scanf("%d%d", &x, &y);			
			if(judge(x,y) || judge(x+n,y+n)) {
				flag=1;
				break;
			}
			else {
				merge(x,y+n);
				merge(x+n,y);
			}
			
		}
		printf("Scenario #%d:\n", z);
		if(flag==1) printf("Suspicious bugs found!\n\n");
		else printf("No suspicious bugs found!\n\n");
	}
}
