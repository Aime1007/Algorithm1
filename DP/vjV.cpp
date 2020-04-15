#include <iostream>
using namespace std;
const int MAXN = 32770;
int n;
int type[]={1,2,3};
int dp[MAXN];
void solve() {
	dp[0]=1;
	for(int i=0; i<3; i++) {
		for(int j=type[i]; j<MAXN; j++) {
			dp[j]=dp[j]+dp[j-type[i]];
		}
	}
}
int main() {
	solve();
	while(cin>>n) {
		cout << dp[n] <<endl;
	}
}
