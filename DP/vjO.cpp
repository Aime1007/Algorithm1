#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 1005;
int n;
int v[MAXN];
int dp[MAXN];
int ans;
void solve() {
	memset(dp,0,sizeof(dp));
	for(int i=1; i<=n; i++) {
		for(int j=0; j<i; j++) {
			if(v[j]<v[i]) {
				dp[i]=max(dp[i],dp[j]+v[i]);
			}
		}
	}
	ans=0;
	for(int i=1; i<=n; i++) ans=max(ans,dp[i]);
}
int main() {
	while(cin>>n && n) {
		for(int i=1; i<=n; i++) {
			cin>>v[i];
			dp[i]=v[i];
		}
		solve();
		cout << ans <<endl;
	}
}
