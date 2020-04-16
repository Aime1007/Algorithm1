#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e4+5;
int dp[MAXN];
int s[MAXN];
int v[MAXN];
int k,ans;
void solve() {
	ans=0;
	dp[0]=s[0];
	for(int i=1; i<k; i++) {
		if(s[i]>dp[i-1]+s[i]) {
			dp[i]=s[i];
			v[i]=i;
		}
		else {
			dp[i]=dp[i-1]+s[i];
			v[i]=v[i-1];
		}
//		dp[i]=max(s[i],dp[i-1]+s[i]);
//		ans=max(dp[i],ans);
		if(dp[i]>dp[ans]) {
			ans=i;
		}
	}

}
int main() {
	while(cin>>k && k) {
		int flag=0;
		for(int i=0; i<k; i++) {
			cin>>s[i];
			if(s[i]>=0) flag=1;
		}
		if(flag==0) {
			cout <<"0"<<" "<< s[0] <<" "<< s[k-1] <<endl;
		}
		else {
			solve();
			cout << dp[ans] <<" "<< s[v[ans]] <<" "<< s[ans] <<endl;
		}
	}
	
}
