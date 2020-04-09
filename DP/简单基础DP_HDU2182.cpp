#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 105;
int insect[MAXN];
//now_coordinate  jump_cnt --> all_insect
int dp[MAXN][MAXN];
int n,a,b,k;
void solve() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=k; j++) {
			for(int z=i+a; z<=i+b && z<=n; z++) {
				dp[z][j]=max(dp[z][j],dp[i][j-1]+insect[z]);
			}
		}
		
	}
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		memset(dp,0,sizeof(dp));
		cin >> n >> a >> b >> k;
		for(int i=1; i<=n; i++) {
			cin >> insect[i];
		}
		solve();
		cout << dp[n][k]+insect[1] <<endl;
	}
}
