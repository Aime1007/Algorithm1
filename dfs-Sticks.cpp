#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 70;
int n,len,cnt;
int a[maxn];
int v[maxn];
bool dfs(int num, int cab, int last) {
	if(num>cnt) {
		return true;
	}
	if(cab==len) {
		return dfs(num+1, 0, 1);
	}
	int fail = 0;
	for(int i = last; i<=n; i++) {
		if(!v[i] && cab+a[i]<=len && fail!=a[i]) {
			v[i]=1;
			if(dfs(num, cab+a[i], i+1)) return true;
			fail = a[i];
			v[i]=0;
			if(cab==0 || cab+a[i]==len) return false;
		}
	}
	return false;
}
int main() {
	while(cin>>n&&n) {
		int sum = 0, val = 0;
		memset(a,0,sizeof(a));
		for(int i=1; i<=n; i++) {
			cin >> a[i];
			sum+=a[i];
			val = max(val, a[i]);
		}
		sort(a+1, a+n+1); reverse(a+1, a+n+1);
		for( len=val; len<=sum; len++) {
			if(sum%len) continue;
			cnt = sum/len;
			memset(v, 0, sizeof(v));
			if(dfs(1,0,1)) break;
		}
		cout << len << endl;
	}
	
}
