#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
const int maxn=1e5;
typedef long long ll;
int main() {
	ll x;
	ll ans;
	cin>>x;
	for(int i=0; ;i++) {
		ll y1=x+i;
		ll y2=x-i;
		if(sqrt(y1)==(ll)(sqrt(y1))) {
			ans=y1;
			break;
		}
		if(sqrt(y2)==(ll)(sqrt(y2))) {
			ans=y2;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}

