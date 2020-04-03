#include <iostream>
#define ll long long
using namespace std;
const int MOD = 200907;

ll quickpow(ll m, ll n) {
	ll ans=1;
	while(n) {
		if(n&1) {
			ans = (ans*m)%MOD;
		}
		m = (m*m)%MOD;
		n>>=1;
	}
	return ans;
} 
int main() {
	ll n;
	cin >> n;
	while(n--){
		ll a,b,c,k;
		cin >> a >> b >> c >> k;
		ll ans;
		if(c-b==b-a) {
			ll d=(b-a);
			ans=(d*k-d+a)%MOD;
		}
		else if(c/b==b/a){
			ll d=(b/a);
			ans=(a*quickpow(d,k-1))%MOD;
		}
		cout << ans << endl;
	}
}
