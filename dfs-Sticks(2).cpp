#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 70;
int n, len, cnt;
int a[maxn], v[maxn];
bool dfs(int num, int l, int last) {
	if(num>cnt) return true;
	if(l==len) return dfs(num+1, 0, 1);
	int fail=0;
	for(int i=last; i<=n; i++) {
		if(!v[i] && l+a[i]<=len && fail!=a[i]) {
			v[i]=1;
			if(dfs(num, l+a[i], i+1)) return;
			fail = a[i];
			v[i]=0;
			if(l==0 || l+a[i]==len) return false;
		}
	}
	return false;
}
int main() {
	while(cin >>n&&n) {
		int sum=0;
		for(int i=1; i<=n; i++) {
			cin >> a[i];
			sum+=a[i];
		}
		
		sort(a+1,a+n+1);
		reverse(a+1,a+n+1);
		for(int len=a[1]; len<=sum; len++) {
			if(sum%len) continue;
			cnt=sum/len;
			if(dfs(1,0,1)) break;
		}
		cout << cnt <<endl;
	}
}
