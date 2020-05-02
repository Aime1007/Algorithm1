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
		d[x]=1;
		size[y]+=size[x];		
	}
}
int main() {
	cin>>t;
	for(int z=1; z<=t; z++) {
		cin>>n>>q;
		init();
		char ch;
		int flag=0;
		for(int i=1; i<=q; i++) {
			cin>>ch;
			if(ch=='T') {
				int a,b;
				cin>>a>>b;
				merge(a,b);
			}
			else {
				int a;
				cin>>a;
				if(flag==0) {
					cout<<"Case "<<z<<":"<<endl;
					flag=1;
				}
				cout<< get(a) <<" "<< size[get(a)] <<" "<< d[a] <<endl;
			}
		}
	}
} 
