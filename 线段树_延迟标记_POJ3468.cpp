#include <iostream>
#include <cstdio>
#define l(x) tree[x].l
#define r(x) tree[x].r
#define sum(x) tree[x].sum
#define add(x) tree [x].add 
using namespace std;
const int maxn = 1e5+5;
typedef long long ll;
int n,q;
int a[maxn];
struct tree {
	int l,r;
	ll sum,add;
}tree[maxn*4];

void build(int p,int l,int r) {
	l(p)=l;
	r(p)=r;
	if(l==r) {
		sum(p)=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	sum(p)=sum(p*2)+sum(p*2+1);
}

void tag(int p) {
	if(add(p)) {
		sum(p*2)+=add(p)*(r(p*2)-l(p*2)+1);
		sum(p*2+1)+=add(p)*(r(p*2+1)-l(p*2+1)+1);
		add(p*2)+=add(p);
		add(p*2+1)+=add(p);
		add(p)=0;
	}
}
void change(int p,int l,int r,int d) {
	if(l<=l(p) && r>=r(p)) {
		sum(p)+=(ll)d*(r(p)-l(p)+1);
		add(p)+=d;
		return ;
	}
	tag(p);
	int mid=(l(p)+r(p))/2;
	if(l<=mid) change(p*2,l,r,d);
	if(r>mid) change(p*2+1,l,r,d);
	sum(p)=sum(p*2)+sum(p*2+1);
}
ll ask(int p,int l,int r) {
	if(l<=l(p) && r>=r(p)) return sum(p);
	tag(p);
	int mid=(l(p)+r(p))/2;
	ll val=0;
	if(l<=mid) val+=ask(p*2,l,r);
	if(r>mid) val+=ask(p*2+1,l,r);
	return val;
}
int main() {
	cin >> n >> q;
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
	}
	build(1,1,n);
	while(q--) {
		char op[2]; int l,r,d;
		scanf("%s%d%d",op,&l,&r);
		if(op[0]=='C') {
			scanf("%d", &d);
			change(1,l,r,d);
		}
		else printf("%lld\n", ask(1,l,r));
	}
}
