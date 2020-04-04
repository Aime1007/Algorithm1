#include <iostream>
using namespace std;
const int MONEY = 251;
int type[5] = {1,5,10,25,50};
int dp[MONEY][101]={0};
void solve() {
	dp[0][0]=1;
	for(int i=0; i<5; i++) {
		for(int j=1; j<101; j++) {
			for(int k=type[i]; k<MONEY; k++) {
				dp[k][j] += dp[k-type[i]][j-1];
			}
		}
	}
}
int main() {
	int s;
	int ans[MONEY] = {0};
	solve();
	for(int i=0; i<MONEY; i++) {
		for(int j=0; j<101; j++) {
			ans[i] += dp[i][j];
		}
	}
	while(cin>>s) cout<< ans[s] <<endl;
}
