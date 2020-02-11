#include <iostream>
using namespace std;
const int maxn = 1050;
int s[maxn];
int height[maxn];
void init() {
	for(int i=1; i<=maxn; i++) {
		s[i] = i;
		
		height[i] = 0;
	}
}
int find(int x) {
	if(x != s[x]) s[x]=find(s[x]);
	return s[x];
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if(height[x]==height[y]) {
		height[x] = height[x]+1;
		s[y] = x;
	}
	else {
		if(height[x] < height[y]) s[x] = y;
		else s[y] = x;
	}
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
