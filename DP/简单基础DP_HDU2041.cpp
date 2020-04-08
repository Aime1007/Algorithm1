#include <iostream>
using namespace std;
const int MAXN = 45;
int dp[MAXN];
void solve() {
	dp[1]=1;
	dp[2]=1;
	for(int i=3; i<=MAXN; i++) {
		dp[i]=dp[i-1]+dp[i-2];
	}
}
int main() {
	solve();
	int n;
	cin >> n;
	for(int i=1; i<=n; i++) {
		int m;
		cin >> m;
		cout << dp[m] <<endl;
	}
}
