#include <iostream>
#include <cstring>
#define max(a,b) (a>b ? a:b)
using namespace std;
int a[10];
bool dp[10][10];
int N;
int S;
bool rec() {
	
}

int main() {
	cin >> N >> S;
	for(int i=0; i<N; i++) {
		cin >> a[i];
	}
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if( j==0) dp[i][j] = true;
			else if( i==0) {
				dp[i][j] = (a[i]==a[i+1]);
			}
			else if(a[i]>S) {
				dp[i][j] = dp[i-1][j];
			}
			else {
				dp[i][j] = (dp[i-1][j-a[i]] || dp[i-1][j]);
			}
		}
	}
	
	if(dp[N-1][S])
		cout << "true";
	else 
		cout << "false";
}
/*
求sum是否能等于s 
*/
