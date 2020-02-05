#include <iostream>
#include <algorithm> 
using namespace std;
int dp[100];
int type[5]= {1,5,10,20,50};
int main() {
	int n;
	cin >>n;
	dp[0]=0;
	for(int i=0; i<n; i++) {
		for(int j=type[i]; j<5; j++)
			dp[j]=min(dp[j], dp[j-type[i]]+1);
	}
	cout<< dp[n];
}
