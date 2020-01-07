#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#define max(a,b) (a>b ? a:b)
using namespace std;
const int MAXN=105;
int n;
int w[MAXN],v[MAXN];
int W;
int res(int i,int j) {
	int ans;
	if( i==n ) ans = 0;
	else if (j<w[i]) {
		ans = res(i+1, j);
	}
	else {
		ans = max(res(i+1, j), res(i+1, j-w[i])+v[i]);
	}
	return ans;
}
int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d %d", &w[i], &v[i]);
	}
	scanf("%d", &W);
	
	printf("%d", res(0,W));
}
