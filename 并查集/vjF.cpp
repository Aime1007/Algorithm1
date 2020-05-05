#include <iostream>
using namespace std;
const int maxn = 3*50000+5;
int fa[maxn];
void init() {
	for(int i=1; i<=3*50000; i++) {
		fa[i]=i;
	}
}
int get(int x) {
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y) {
	fa[get(x)]=get(y);
}
bool judge(int x, int y) {
	if(get(x)==get(y)) return true;
	return false;
}
int main() {
	int n,k;
	scanf("%d%d", &n, &k);
	init();
	int ans=0;
	for(int i=1; i<=k; i++) {
		int d,x,y;
		scanf("%d%d%d", &d, &x, &y);
		if( x<1 || x>n || y<1 || y>n) {
			ans++;
			continue;
		}
		if(d==1) {
			if(judge(x,y+n) || judge(x,y+2*n)) ans++;
			else {
				merge(x,y);
				merge(x+n,y+n);
				merge(x+2*n,y+2*n);				
			}
		}
		else {
			if(judge(x,y) || judge(x,y+n) || x==y) ans++;
			else {
				merge(x,y+2*n);
				merge(x+n, y);
				merge(x+2*n, y+n);				
			}

		}
	}
	printf("%d\n", ans);
}
