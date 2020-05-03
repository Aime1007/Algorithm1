#include <iostream>
using namespace std;
const int maxn = 10005;
int t,n,q;
int root[maxn];
int size[maxn];
int d[maxn];
void init() {
	for(int i=1; i<=n; i++) {
		root[i]=i;
		size[i]=1;
		d[i]=0;
	}
}
int get(int x) {
	if(x==root[x]) return x;
	int r=root[x];
	root[x]=get(root[x]);
	d[x]+=d[r];
	return root[x];
}
void merge(int x,int y) {
	x=get(x);
	y=get(y);
	if(x != y) {
		root[x]=y;
		size[y]+=size[x];
		d[x]=1;
	}
}
int main() {
	scanf("%d", &t);
	for(int z=1; z<=t; z++) {
		scanf("%d%d", &n, &q);
		getchar();
		init();
		char ch;
		int flag=0;
		for(int i=1; i<=q; i++) {
			scanf("%c", &ch);
			if(ch=='T') {
				int a,b;
				scanf("%d%d", &a, &b);
				getchar();
				merge(a,b);
			}
			else {
				int a;
				scanf("%d", &a);
				getchar();
				if(flag==0) {
					printf("Case %d:\n", z);
					flag=1;
				}
				int r=get(a);
				printf("%d %d %d\n", r, size[r], d[a]);
			}
		}
	}
} 
