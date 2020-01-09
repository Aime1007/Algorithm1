#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#define max(a,b) (a>b ? a:b)
using namespace std;
const int MAXN=105;
int dp[MAXN][MAXN];
int w[MAXN],v[MAXN];
int n;
int W;

int main() {
	cin >> n;
	for(int i=0; i<n; i++) {
		scanf("%d %d", &w[i], &v[i]);
	}
	scanf("%d", &W);
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<=W; j++) {
			if( j<w[i]) {
				dp[i+1][j]=dp[i][j];
			}
			else {
				dp[i+1][j]=max(dp[i][j],dp[i][j-w[i]]+v[i]);
			}
		}
	}
	cout << dp[n][W] <<endl;
} 
/*
4
2 3
1 3
6 4
2 2
5
*/
