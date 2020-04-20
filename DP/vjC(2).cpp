//dp[n_bones][now_volume]=max_value
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 1005;
int n,v;
int value[MAXN],volume[MAXN];
int dp[MAXN][MAXN];
void solve() {
	memset(dp,0xcf,sizeof(dp));
	dp[0][0]=0;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=v; j++)
			dp[i][j]=dp[i-1][j];
		for(int j=volume[i]; j<=v; j++)
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-volume[i]]+value[i]);
	}
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		cin>>n>>v;
		for(int i=1; i<=n; i++) cin>>value[i];
		for(int i=1; i<=n; i++) cin>>volume[i];
		solve();
		cout << dp[n][v] <<endl;
	}
}
