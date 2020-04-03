#include <iostream>
#define ll long long
using namespace std;
ll quickpow(ll m, ll n) {
	ll ans=1;
	while(n) {
		if(n&1) {
			ans *= m;
			ans %= 10;
		}
		m *= m;
		m %= 10;
		n>>=1;
	}
	return ans;
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		ll ans= quickpow(n,n)%10;
		cout <<ans<<endl; 
	}
}
