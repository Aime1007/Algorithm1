#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5+5;
int dp[MAXN];
int s[MAXN];
int v[MAXN];
int k,ans;
void solve() {
	ans=1;
	dp[1]=s[1];
	v[1]=1;
	for(int i=2; i<=k; i++) {
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
	int t;
	cin>>t;
	for(int i=1; i<=t; i++){
		cin>>k;
		for(int j=1; j<=k; j++) {
			cin>>s[j];
		}
		solve();
		cout <<"Case "<< i <<":"<<endl;
		cout << dp[ans] <<" "<< v[ans] <<" "<< ans <<endl;
		if(i!=t) cout <<endl;
	}
	
}
