//dp[now_coordinate][now_step]=max_insects
#include <iostream>
#include <algorithm> 
using namespace std;
const int MAXN = 105;
int n,a,b,z;
int insects[MAXN];
int dp[MAXN][MAXN];
void solve() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=z; j++) {
			for(int k=i+a; k<=i+b && k<=n; k++) {
				dp[k][j]=max(dp[k][j],dp[i][j-1]+insects[k]);
			}
		}
	}
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> a >> b >> z;
		for(int i=1; i<=n; i++) cin >> insects[i];
		solve();
		cout << dp[n][z]+insects[1] <<endl;
	}
}
