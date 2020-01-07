#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#define max(a,b) (a>b ? a:b)
using namespace std;
const int MAXN=105;
int n;
int w[MAXN],v[MAXN];
int W;
int dp[MAXN][MAXN];
int res(int i, int j) {
	if(dp[i][j] >=0) {
		return dp[i][j];
	}
	int ans;
	if( i==n ) {
		ans = 0;
	}
	else if( j<w[i]) {
		ans = res(i+1, j);
	}
	else {
		ans = max(res(i+1, j), res(i+1, j-w[i])+v[i]);
	}
	return dp[i][j] = ans;
} 
int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d %d", &w[i], &v[i]);
	}
	scanf("%d", &W);
	
	memset(dp, -1, sizeof(dp));
	printf("%d", res(0,W));
}
