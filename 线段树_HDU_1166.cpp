#include <iostream>
using namespace std;
const int maxn = 50005;
int a[maxn];
struct node {
	int l,r;
	int sum;
}tree[maxn<<2];
void build(int p,int l,int r) {
	tree[p].l=l;
	tree[p].r=r;
	if(l==r) {
		tree[p].sum=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build((p<<1)+1,mid+1,r);
	tree[p].sum=tree[p<<1].sum+tree[(p<<1)+1].sum;
}
void change(int p,int x,int v,int flag) {
	if(tree[p].l==tree[p].r) {
		if(flag==0) tree[p].sum+=v;
		else tree[p].sum-=v;
		return ;
	}
	int mid=(tree[p].l+tree[p].r)>>1;
	if(x<=mid) change(p<<1,x,v,flag);
	else change((p<<1)+1,x,v,flag);
	tree[p].sum=tree[p<<1].sum+tree[(p<<1)+1].sum;
}
int ask(int p,int l,int r) {
	if(l==tree[p].l && r==tree[p].r) {
		return tree[p].sum;
	}
	
	int mid = (tree[p].l+tree[p].r)>>1;
	if(l<=mid) {
		if(r>mid) {
			return ask(p<<1,l,mid)+ask((p<<1)+1,mid+1,r);
		}
		else {
			return ask(p<<1,l,r);
		}
	}
	else {
		return ask((p<<1)+1,l,r);
	}

//	if(r<=mid) {
//		return ask(p<<1,l,r);
//	}
//	else {
//		if(l>mid) return ask((p<<1)+1,l,r);
//		else return ask(p<<1,l,mid)+ask((p<<1)+1,mid+1,r);
//	}
}
int main() {
	int t;
	cin >> t;
	for(int k=1; k<=t; k++) {
		int n;
		cin >> n;
		for(int i=1; i<=n; i++) {
			cin >> a[i];
		}
		build(1,1,n);
		char s[10];
		int i,j;
		cout<<"Case "<<k<<":"<<endl;
		while(1) {
			scanf("%s", s);
			if(s[0]=='E') break;
			cin >> i >> j;
			if(s[0]=='A') {
				change(1,i,j,0);
			}
			else if(s[0]=='S') {
				change(1,i,j,1);
			}
			else if(s[0]=='Q') {
				cout<< ask(1,i,j) <<endl;
			}
		}
	}
}
