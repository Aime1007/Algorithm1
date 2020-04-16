#include <iostream>
using namespace std;
const int MAXN = 45;
int n;
int v[MAXN];
int dp[MAXN];
void solve() {
	dp[0]=1;
	for(int i=1; i<=n; i++) {
		for(int j=v[i]; j<=40; j++) {
			dp[j]=dp[j-v[i]]+1;
		}
	}
}
int main() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin>>v[i];
	}
	solve();
	cout << dp[40] <<endl;
}
