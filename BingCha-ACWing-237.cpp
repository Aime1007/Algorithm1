#include <iostream>
using namespace std;
const int maxn=1e6+5;
int t,n,cnt;
int root[maxn<<1];
int d[maxn<<1];
int ii[maxm];
int jj[maxm];
int ee[maxm];
void discrete(int cnt) {
	sort(d+1,d+cnt+1);
	int m=unique(d+1,d+cnt+1)-d-1;
	for(int i=1; i<=cnt; i++) {
		ii[i]=lower_bound(d+1,d+m+1,ii[i])-d;
		jj[i]=lower_bound(d+1,d+m+1,yy[i])-d;
	}
}
void init() {
	for(int i=1; i<=2*n; i++) {
		root[i]=i;
	}
}
int get(int x) {
	if(x==root[x]) return x;
	return root[x]=get(root[x]);
}
void merge(int x,int y) {
	root[get(x)]=get(y);
}
bool judge(int x,int y) {
	int a=get(x);
	int b=get(y);
	if(a==b) return true;
	else return false;
}
int main() {
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int k=1; k<=n; k++) {
			cin >> ii[k] >> jj[k] >> ee[k];
			d[++sum]=ii[k];
			d[++sum]=jj[k];
		}
		discrete(sum);
		for(int k=1; k<=n; k++) {
			if(ee[k]==1) merge(ii[i],jj[i]);
			else unequal
				if(judge(ii[k],jj[k])) cout<<"YES"<<endl;
				else cout<<"NO"<<endl;
			}
		}
	}
}
