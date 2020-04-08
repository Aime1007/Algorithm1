#include <iostream>
using namespace std;
const int MAXN = 56;
int dp[MAXN];
int main() {
	int n;
	dp[1]=1;
	dp[2]=2;
	dp[3]=3;
	dp[4]=4;
	dp[5]=6;
	for(int i=6; i<MAXN; i++) {
		dp[i]=dp[i-1]+dp[i-3];
	}
	while(cin>>n && n) {
		cout << dp[n] <<endl;
	}
}
