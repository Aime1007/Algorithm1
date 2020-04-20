#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 105;
int n,m,k,s;
int a[MAXN];
int b[MAXN];
// 忍耐 杀怪数 -》经验值
int dp[MAXN][MAXN];
void solve() {
	for(int ii=1; ii<=k; ii++) {
//		int x=min(s,m/b[ii]);
//		while(x--) {
			for(int i=m; i>=b[ii]; i--)
				for(int j=1; j<=s; j++)
					dp[i][j]=max(dp[i][j],dp[i-b[ii]][j-1]+a[ii]);
//		}
	}
}
int main() {
	while(cin>>n>>m>>k>>s) {
		memset(dp,0,sizeof(dp));
		for(int i=1; i<=k; i++) {
			cin >>a[i]>>b[i];
		}
		solve();
		int ans=m+1;

		for(int i=1; i<=m; i++) {
			for(int j=1; j<=s; j++) {
				if(dp[i][j]>=n) {
					if(ans>i) ans=i;
				}
			}
		}

		cout << m-ans <<endl;
	}

}
