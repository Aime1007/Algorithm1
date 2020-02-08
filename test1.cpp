#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
ll a[105];
ll b[105];
ll gcd(ll a, ll b) {
	if( b==0) return a;
	return gcd(b, a%b);
}
int main() {
	int N;
	cin >> N;
	for(int i=0; i<N; i++) {
		scanf("%lld/%lld", &a[i], &b[i]);
	}
	ll sum1=a[0];//总分子 
	ll sum2=b[0];//总分母 
	
	for(int i=1; i<N; i++) {
		ll t=sum2*b[i]/gcd(sum2, b[i]);//t最小公倍数 
		ll fm=b[i]*(t/b[i]);
		ll fz=sum1*(t/sum2)+a[i]*(t/b[i]);
		sum1=fz/gcd(fz, fm);
		sum2=fm/gcd(fz, fm);
	}

	ll ans=sum1/sum2;
	if(ans!=0) {
		cout << ans;
		if(sum1%sum2!=0) {
			cout<<" "<< sum1%sum2/gcd(sum1, sum2) <<"/"<< sum2/gcd(sum1, sum2);
		}
	}
	else if(sum1==0) {
		cout<<0;
	}
	else {
		cout << sum1%sum2/gcd(sum1, sum2) <<"/"<< sum2/gcd(sum1, sum2);
	}
} 
