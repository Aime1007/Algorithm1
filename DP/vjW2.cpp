//dp[time][coordinate]
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n,k;
int mouse[22][12];
int dp[22][12];
void solve() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=k; j++) {
			for(int z=1; z<=k; z++) {
				dp[i][j]=min(dp[i][j],abs(mouse[i-1][z]-mouse[i][j])+dp[i-1][z]);
			}
		}
	}
}
int main() {
	while(cin>>n>>k) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=k; j++) {
				cin>>mouse[i][j];
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=k; j++) {
				dp[i][j]=505;
				dp[1][j]=0;
			}
		}
		solve();
		int ans=1;
		for(int i=1; i<=k; i++) {
			if(dp[n][i]<dp[n][ans]) ans=i;
			
		}
		cout << dp[n][ans] <<endl;
	}
}
