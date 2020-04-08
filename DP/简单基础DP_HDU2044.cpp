#include <iostream>
using namespace std;
const int MAXN=51;
int dp[MAXN];
void solve() {
	dp[1]=0;
	dp[2]=1;
	dp[3]=2;
	for(int i=4; i<=MAXN; i++) {
		dp[i]=dp[i-1]+dp[i-2];
	}
}
int main() {
	solve();
	int n;
	cin >> n;
	for(int i=1; i<=n; i++) {
		int a,b;
		cin >> a >> b;
		cout << dp[b-a+1] <<endl;
	}
} 
