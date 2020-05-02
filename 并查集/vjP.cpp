#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e7+5;
int root[maxn];
int size[maxn];
int ans;
void init() {
	for(int i=1; i<=1e7; i++) {
		root[i]=i;
		size[i]=1;
	}
}
int get(int x) {
	if(x==root[x]) return x;
	return root[x]=get(root[x]);
}
void merge(int x,int y) {
	x=get(x);
	y=get(y);
	//x!=y ¿ÓËÀ¡£¡£ 
	if(x != y) {
		root[x]=y;
		size[y]+=size[x];		
	}

}
int main() {
	int n;
	while(~scanf("%d", &n)) {
		init();
		ans=0;
		for(int i=1; i<=n; i++) {
			int a,b;
			scanf("%d%d", &a, &b);
			merge(a,b);
		}
		for(int i=1; i<=1e7; i++) {
            if(size[i]>ans) {
                ans=size[i];
            }
        }
		printf("%d\n", ans);
	}
}
