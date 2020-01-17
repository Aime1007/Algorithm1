#include <iostream>
#include <cstring>
#define max(a,b) (a>b ? a:b)
using namespace std;

int a[10];
int N;
int dp[10];

int main() {
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> a[i];
	}
	memset(dp,0,sizeof(dp));
	
	dp[0]=a[0];
	dp[1]=max(a[0],a[1]);
	for(int i=2; i<N; i++) {
		dp[i]=max(dp[i-2]+a[i], dp[i-1]);
	}
	
	cout << dp[N-1];
}
/*
1 2 4 1 7 8 3
4 1 1 9 1
*/
