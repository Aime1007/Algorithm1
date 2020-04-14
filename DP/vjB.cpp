//dp[i][j]=max_value
#include <iostream>
using namespace std;
int dp[101][101];
int main() {
	int n;
	cin >> n;
	for(int i=1; i<=n; i++)
	for(int j=1; j<=i; j++)
	cin>>dp[i][j];
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=i; j++) {
			dp[i][j]+=max(dp[i-1][j],dp[i-1][j-1]);
		}
	}
	int ans=0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(dp[i][j]>ans) {
				ans=dp[i][j];
			}
		}
	}
	cout << ans <<endl;
}
