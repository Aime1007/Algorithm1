#include <iostream>
using namespace std;
const int maxn = 1050;
int s[maxn];
void init() {
	for(int i=1; i<=maxn; i++) {
		s[i] = i;
	}
}
int find(int x) {
	return x==s[x]? x:find(s[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if(x != y) s[x] = s[y];
}

int main() {
	int t, n, m, x, y;
	cin >>t;
	while(t--) {
		cin >>n >>m;
		init();
		for(int i=1; i<=m; i++) {
			cin >> x >> y;
			merge(x, y);
		}
		int ans = 0;
		for(int i=1; i<=n; i++) {
			if(s[i]==i) ans++;
		}
		cout << ans <<endl;
	}
}
