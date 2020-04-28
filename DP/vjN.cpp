#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[100005];
int c[1005];
int v[1005];
int dp[100005];
int n,m;
void solve() {
	dp[0]=1;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=m; j++) v[j]=0;
		for(int j=a[i]; j<=m; j++) {
			if(!dp[j] && dp[j-a[i]] && v[j-a[i]]<c[i]) {
				dp[j]=1;
				v[j]=v[j-a[i]]+1;
			}
		}
	}
}
int main() {
	
	while(cin>>n>>m) {
		if(n==0 && m==0) break;
		memset(dp,0,sizeof(dp));
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		for(int i=1; i<=n; i++) {
			cin>>c[i];
		}
		solve();
		int ans=0;
		for(int i=1; i<=m; i++) {
			ans+=dp[i];
		}
		cout << ans <<endl;
	}
}
