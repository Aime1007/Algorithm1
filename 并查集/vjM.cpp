#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 505*3;
int n,m;
int fa[maxn];
void init() {
	for(int i=0; i<=3*n; i++) {
		fa[i]=i;
	}
}
int get(int x) {
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}
void merge(int x, int y) {
	int rx=get(x);
	int ry=get(y);
	if(rx==ry) return;
	fa[get(x)]=get(y);
}
bool judge(int x,int y) {
	if(get(x)==get(y)) return true;
	return false;
}
int main() {
	int x[maxn],y[maxn];
	char c[maxn];
	int flag[maxn];
	while(~scanf("%d%d", &n, &m)) {

		for(int i=0; i<m; i++) {
			
			scanf("%d%c%d", &x[i], &c[i], &y[i]);
		}
		int cnt=0;
		int last_step=0,Judge;
		int d;
		for(int i=0; i<n; i++) {
			memset(flag,0,sizeof(flag));
			init();
			int f=0;
			for(int j=0; j<m; j++) {
				if(x[j]==i || y[j]==i) continue;
				
				if(c[j]=='=') {
					if(judge(x[j],y[j]+n) || judge(x[j],y[j]+2*n)) {
						f=1;
						if(j+1>last_step) {
							last_step=j+1;
						}
						break;
					}
					else {
						merge(x[j],y[j]);
						merge(x[j]+n,y[j]+n);
						merge(x[j]+2*n,y[j]+2*n);
					}
				}
				else if(c[j]=='<'){
					if(judge(x[j],y[j]) || judge(x[j],y[j]+n)) {
						f=1;
							if(j+1>last_step) {
							last_step=j+1;
						}
						break;
					}
					else {
						merge(x[j],y[j]+2*n);
						merge(x[j]+n,y[j]);
						merge(x[j]+2*n,y[j]+n);
					}
				}
				else {
					if(judge(x[j],y[j]) || judge(x[j],y[j]+2*n)) {
						f=1;
							if(j+1>last_step) {
							last_step=j+1;
						}
						break;
					}
					else {
						merge(x[j]+2*n,y[j]);
						merge(x[j],y[j]+n);
						merge(x[j]+n,y[j]+2*n);
					}
				}
			}
			if(f==0) {
				cnt++;
				Judge=i;
			}
		}
		if(cnt==0) printf("Impossible\n");
		else if(cnt == 1) printf("Player %d can be determined to be the judge after %d lines\n",Judge, last_step);
		else printf("Can not determine\n");
	}
}
