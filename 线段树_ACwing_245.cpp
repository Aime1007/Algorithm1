#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=5e5+5;
int n,m;
int a[maxn];
struct node {
	int l,r;
	int sum,dat,lmax,rmax;
}t[maxn*4];
void build(int p, int l, int r) {
	t[p].l=l, t[p].r=r;
	if(l==r) {
		t[p].dat=t[p].sum=t[p].lmax=t[p].rmax=a[l];
		return ;
	}
	int mid=(l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	t[p].sum=t[p*2].sum+t[p*2+1].sum;
	t[p].lmax=max(t[p*2].lmax,t[p*2].sum+t[p*2+1].lmax);
	t[p].rmax=max(t[p*2+1].rmax,t[p*2+1].sum+t[p*2].rmax);
	t[p].dat=max(t[p*2].dat,max(t[p*2+1].dat,t[p*2].rmax+t[p*2+1].lmax));
}
void change(int p, int x, int v) {
	if(t[p].l==t[p].r) {
		t[p].dat=v;
		t[p].sum=v;
		t[p].lmax=v;
		t[p].rmax=v;
		return;
	}
	int mid=(t[p].l+t[p].r)/2;
	if(x<=mid) change(p*2,x,v);
//	else change(p<<1|1,x,v);
	else change(p*2+1,x,v);
	t[p].sum=t[p*2].sum+t[p*2+1].sum;
	t[p].lmax=max(t[p*2].lmax,t[p*2].sum+t[p*2+1].lmax);
	t[p].rmax=max(t[p*2+1].rmax,t[p*2+1].sum+t[p*2].rmax);
	t[p].dat=max(t[p*2].dat,max(t[p*2+1].dat,t[p*2].rmax+t[p*2+1].lmax));
}
node ask(int p,int l,int r) {
	if(l<=t[p].l && r>=t[p].r) return t[p];
	int mid=(t[p].l+t[p].r)/2;
	int val=-(1<<30);
	node a,b,c;
	a.dat=a.sum=a.lmax=a.rmax=val;
	b.dat=b.sum=b.lmax=b.rmax=val;
	c.dat=c.lmax=c.rmax=val;
	c.sum=0;
	if (l<=mid&&r<=mid){
        a=ask(p*2,l,r);
        c.sum+=a.sum;
    }
	else if(l>mid && r>mid) {
		b=ask(p*2+1,l,r);
		c.sum+=b.sum;
	}
	else {
		a=ask(p*2,l,r);
		b=ask(p*2+1,l,r);
		c.sum+=a.sum+b.sum;
	}
	c.dat=max(c.dat,max(max(a.dat,b.dat),a.rmax+b.lmax));
	c.lmax=max(c.lmax,max(a.lmax,a.sum+b.lmax));
	c.rmax=max(c.rmax,max(b.rmax,b.sum+a.rmax));
	return c;
}
int main() {
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	build(1,1,n);
	for(int i=1; i<=m; i++) {
		int k,x,y;
		cin >> k >> x >> y;
		if(k==1) {
			if(x>y) swap(x,y);
			cout<< ask(1,x,y).dat <<endl;
		}
		else {
			change(1,x,y);
		}
	}
}
