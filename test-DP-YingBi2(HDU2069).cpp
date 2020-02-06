#include <iostream>
using namespace std;
const int MAX_N=105;
const int MAX_V=255;
int value[5]={1,5,10,25,50};
int dp[MAX_V][MAX_N]={0};
void solve() {
	dp[0][0]=1;
	for(int i=0; i<5; i++) {
		for(int j=1; j<MAX_N; j++) {
			for(int k=value[i]; k<MAX_V; k++) {
				dp[k][j]+=dp[k-value[i]][j-1];
			}
		}
	}
}
int main() {
	int s;
	int ans[MAX_V]={0};
	solve();
	for(int i=0; i<MAX_V; i++) {
		for(int j=0; j<MAX_N; j++) {
			ans[i] += dp[i][j];
		}
	}
	while(cin >>s) {
		cout << ans[s] <<endl;
	}
}
