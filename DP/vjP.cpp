//#include <iostream>
//using namespace std;
//const int MAXN = 45;
//int n;
//int v[MAXN];
//int dp[MAXN];
//void solve() {
//	dp[0]=1;
//	for(int i=1; i<=n; i++) {
//		for(int j=v[i]; j<=40; j++) {
//			dp[j]=dp[j-v[i]]+1;
//		}
//	}
//}
//int main() {
//	cin >> n;
//	for(int i=1; i<=n; i++) {
//		cin>>v[i];
//	}
//	solve();
//	cout << dp[40] <<endl;
//}

#include <iostream>
#include <algorithm>
using namespace std;
int dp[21][41];
int a[21];
int n;
void solve() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=40; j++) {
			if(j<a[i]) {
				dp[i][j]=dp[i-1][j];
			}
			else {
				dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i]];
			}
		}
	}
}
int main() {
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=0; i<=n; i++) dp[i][0]=1;
	solve();
	cout << dp[n][40] <<endl;
}
