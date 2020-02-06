#include <iostream>
#include <algorithm> 
using namespace std;
const int MAX_M=100;
const int MAX_V=5;
int dp[MAX_M];
int value[MAX_V]={1,5,10,25,50};
void solve() {
	for(int i=0; i<MAX_M; i++) {
		dp[i]=INT_MAX;
	}
	dp[0]=0;
	for(int i=0; i<MAX_V; i++) {
		for(int j=value[i]; j<MAX_M; j++) {
			dp[j]=min(dp[j], dp[j-value[i]]+1);
		}
	}
}

int main() {
	int s;
	solve();
	while(cin>>s) {
		cout<< dp[s] <<endl;
	}
}
