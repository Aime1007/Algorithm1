#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 1005;
int dp[MAXN][MAXN];
string s1,s2;
void lcs() {
	memset(dp,0,sizeof(dp));
	for(int i=1; i<=s1.length(); i++) {
		for(int j=1; j<=s2.length(); j++) {
			if(s1[i-1]==s2[j-1]) {
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else {
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
}
int main() {
	while(cin>>s1>>s2) {
		lcs();
		cout << dp[s1.length()][s2.length()] <<endl;
	}
}
