#include <iostream>
using namespace std;
const int maxn = 1e5+5;
int root[maxn];
int h[maxn];
void init() {
	for(int i=1; i<=maxn; i++) {
		root[i]=i;
		h[i]=1;
	}
}
int get(int x) {
	if(x==root[x]) return x;
	return root[x]=get(root[x]);
}
void merge(int x,int y) {
	x=get(x);
	y=get(y);
	if(h[x]==h[y]) {
		h[x]+=1;
		root[y]=x;
	}
	else {
		if(h[x]>h[y]) root[y]=x;
		else root[x]=y;
	}
}
int main() {
	int x,y;
	while(cin>>x>>y) {
		init();
		if(x==-1 && y==-1) break;
		merge(x,y);
		
	}
} 
