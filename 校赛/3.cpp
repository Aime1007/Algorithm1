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
	int t;
	scanf("%d", &t);
	while(t--) {
		ll n,ans;
		scanf("%lld", &n);
		double cnt=1.0*sqrt(1+24*n);
		ans=1.0*(cnt-1)/6;
		printf("%lld\n", ans);
	}
	return 0;
}

