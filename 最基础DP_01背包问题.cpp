#include <iostream>
#include <cstring> 
using namespace std;
int N,V;
struct node {
	int val;
	int vol;
}b[1005];
int dp[1005][1005];
int solve() {
	memset(dp,0,sizeof(dp));
	for(int i=1; i<=N; i++) {
		for(int j=0; j<=V; j++) {
			if(b[i].vol>j)
				dp[i][j]=dp[i-1][j];
			else 
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-b[i].vol]+b[i].val);
		}
	}
	return dp[N][V];
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> N >> V;
		for(int i=1; i<=N; i++) cin >> b[i].val;
		for(int i=1; i<=N; i++) cin >> b[i].vol;
		cout << solve() << endl;
	}
}
