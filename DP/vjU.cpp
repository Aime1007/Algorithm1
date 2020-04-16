#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1005;
int dp[MAXN];
int s[MAXN];
int n;
int solve() {
	int ans=0;
	for(int i=1; i<=n; i++) {
		dp[i]=1;
		for(int j=1; j<i; j++) {
			if(s[j]<s[i]) {
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		ans=max(ans,dp[i]);
	}
	return ans;
}
int main() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> s[i];
	}
	cout << solve() <<endl;
}
