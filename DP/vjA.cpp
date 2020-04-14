//dp[coin_numbers][value]
#include <iostream>
using namespace std;
const int MAXN = 255;
int type[] = {1,5,10,25,50};
int dp[101][MAXN];
void solve() {
	dp[0][0]=1;
	for(int i=0; i<5; i++) {
		for(int j=1; j<=100; j++) {
			for(int k=type[i]; k<MAXN; k++) {
				dp[j][k]=dp[j][k]+dp[j-1][k-type[i]];
			}
		}
	}
}
int main() {
	int n;
	int ans[MAXN] = {0};
	solve();
	for(int i=0; i<MAXN; i++) {
		for(int j=0; j<101; j++) {
			ans[i] += dp[j][i];
		}
	}
	while(cin>>n)
		cout<< ans[n] <<endl;
}
