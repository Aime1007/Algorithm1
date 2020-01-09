#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#define max(a,b) (a>b ? a:b)
#define MAXN 1005
using namespace std;
int n,m;
char s[MAXN];
char t[MAXN];
int dp[MAXN][MAXN];

int main() {
	cin >> n;
	cin >> m;
	for(int i=0; i<n; i++) {
		cin >> s[i];
	}
	for(int i=0; i<m; i++) {
		cin >> t[i];
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(s[i]==t[j]) {
				dp[i+1][j+1] = dp[i][j]+1;
			}
			else {
				dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
			}
		}
	}
	cout << dp[n][m];
} 
/*
4
4
abcd
becd
*/
