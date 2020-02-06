#include <iostream>
#include <algorithm> 
using namespace std;
const int MAX_M=100;
const int MAX_V=5;
int dp[MAX_M];
int value[MAX_V]={1,5,10,25,50};
int Min_path[MAX_M]={0}; 

void solve() {
	for(int i=0; i<MAX_M; i++) {
		dp[i]=INT_MAX;
	}
	dp[0]=0;
	for(int i=0; i<MAX_V; i++) {
		for(int j=value[i]; j<MAX_M; j++) {
			if(dp[j]>dp[j-value[i]]+1) {
				Min_path[j] = value[i];
				dp[j] = dp[j-value[i]]+1;
			}
		}
	}
}
void print(int *Min_path, int s) {
	while(s) {
		cout << Min_path[s] <<" ";
		s = s-Min_path[s];
	}
}
int main() {
	int s;
	solve();
	while(cin>>s) {
		cout<< dp[s] <<endl;
		print(Min_path, s);
	}
}
