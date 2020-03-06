#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 2e6+5;
vector<pair<int,int> > a, b;
int t,cnt;
int m,x,y,c;
int root[N];
int id[N];
void discrete(int cnt) {
	sort(id+1,id+cnt+1);
	cnt = unique(id+1,id+cnt+1)-id-1;
}
int getId(int x) {
	return lower_bound(id+1,id+cnt+1,x)-id;
}
void init() {
	for(int i=1; i<=cnt; i++) {
		root[i]=i;
	}
}
int find(int x) {
	if(x==root[x]) return x;
	return root[x]=find(root[x]);
}
void merge(int x,int y) {
	root[find(x)]=find(y);
}
void solve() {
	init();
	for(int i=0; i<a.size(); i++) {
		int x=getId(a[i].first);
		int y=getId(a[i].second);
		int fx=find(x),fy=find(y);
		root[fx]=fy;
	}
	for(int i=0; i<b.size(); i++) {
		int x=getId(b[i].first);
		int y=getId(b[i].second);
		int fx=find(x),fy=find(y);
		if(fx==fy) {
			cout<<"NO"<<endl;
			return ;
		}
	}
	cout<<"YES"<<endl;
}
int main() {
	cin >> t;
	while(t--) {
		a.clear(); b.clear(); cnt=0;
		cin >> m;
		for(int i=1; i<=m; i++) {
			cin >> x >> y >> c;
			if(c==1) a.push_back(make_pair(x,y));
			else b.push_back(make_pair(x,y));
			id[++cnt]=x;
			id[++cnt]=y;
		}
		discrete(cnt);
		solve();
	}
}
