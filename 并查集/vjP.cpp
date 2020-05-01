#include <iostream>
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
	root[x]=y;
	size[y]+=size[x];
	if(size[y]>ans) ans=size[y];
}
int main() {
	int n;
	while(cin>>n) {
		init();
		ans=0;
		for(int i=1; i<=n; i++) {
			int a,b;
			cin>>a>>b;
			merge(a,b);
		}
		cout<< ans <<endl;
	}
	
}
