#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_M=100;
const int MAX_V=5;
int dp[MAX_M]={0};
int value[MAX_V]={1,5,10,25,50};

void solve() {
	dp[0]=1;
	for(int i=0; i<MAX_V; i++) {
		for(int j=value[i]; j<MAX_M; j++) {
			dp[j]=dp[j]+dp[j-value[i]];
		}
	}
}
int main() {
	int s;
	solve();
	while(cin >> s) {
		cout << dp[s]<<endl;
	}
}
