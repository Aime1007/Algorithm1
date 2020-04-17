#include <iostream>
#include <algorithm>
using namespace std;
int dp[41];
int a[21];
int n;
void solve() {
	for(int i=1; i<=n; i++) {
		for(int j=40; j>=a[i]; j--) {
			dp[j]=dp[j]+dp[j-a[i]];
		}
	}
}
int main() {
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=0; i<=n; i++) dp[0]=1;
	solve();
	cout << dp[40] <<endl;
}
