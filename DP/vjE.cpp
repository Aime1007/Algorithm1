#include <iostream>
#include <algorithm> 
using namespace std;
const int MAXN = 3405;
int n,m;
int weight[MAXN];
int d[MAXN];
int dp[13000];
void solve() {
	for(int i=1; i<=n; i++) {
		for(int j=m; j>=weight[i]; j--) {
			dp[j]=max(dp[j],dp[j-weight[i]]+d[i]);
		}
	}
}
int main() {
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> weight[i] >> d[i];
	}
	solve();
	cout << dp[m] <<endl;
}
