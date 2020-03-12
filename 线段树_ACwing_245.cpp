#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=5e5+5;
int n,m;
int a[maxn];
struct node {
	int l,r;
	int val;
	int sum,dat,lmax,rmax;
}t[maxn*4];
void build(int p, int l, int r) {
	t[p].l=l, t[p].r=r;
	if(l==r) {
		t[p].val=a[p];
		return ;
	}
	int mid=(l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	t[p].val=max(t[p*2].val,t[p*2+1].val);
	t[p].sum=t[p*2].sum+t[p*2+1].sum;
	t[p].lmax=max(t[p*2].lmax,t[p*2].sum+t[p*2+1].lmax);
	t[p].rmax=max(t[p*2+1].rmax,t[p*2+1].sum+t[p*2].rmax);
	t[p].dat=max(max(t[p*2].dat,t[p*2+1].dat),t[p*2].rmax+t[p*2+1].lmax);
}
void change(int p, int x, int v) {
	if(t[p].l==t[p].r) {
		t[p].val=v;
		return;
	}
	int mid=(t[p].l+t[p].r)/2;
	if(x<=mid) change(p*2,x,v);
	else change(p*2+1,x,v);
	t[p].val=max(t[p*2].val,t[p*2+1].val);
	t[p].sum=t[p*2].sum+t[p*2+1].sum;
	t[p].lmax=max(t[p*2].lmax,t[p*2].sum+t[p*2+1].lmax);
	t[p].rmax=max(t[p*2+1].rmax,t[p*2+1].sum+t[p*2].rmax);
	t[p].dat=max(max(t[p*2].dat,t[p*2+1].dat),t[p*2].rmax+t[p*2+1].lmax);
}
int ask(int p,int l,int r) {
	if(l<=t[p].l && r>=t[p].r) return t[p].dat;
	int mid=(t[p].l+t[p].r)/2;
	int dat=-(1<<30);
	if(l<=mid) dat=max(dat,ask(p*2,l,r));
	if(r>mid) dat=max(dat,ask(p*2+1,l,r));
	return dat;
}
int main() {
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	build(1,1,n);
	for(int i=1; i<=3; i++) {
		int k,x,y;
		cin >> k >> x >> y;
		if(x>y) swap(x,y);
		if(k==1) {
			cout<< ask(1,x,y) <<endl;
		}
		else {
			change(1,x,y);
		}
	}
}
