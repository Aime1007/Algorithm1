#include <iostream>
#include <cstring>
using namespace std;
int n;
int dp[125];
void solve() {
	dp[0]=1;
	for(int i=1; i<=120; i++) {
		for(int j=i; j<=120; j++) {
			dp[j]+=dp[j-i];
		}
	}
}
int main() {
	solve();
	while(cin>>n) {
		cout << dp[n] <<endl;
	}
}
