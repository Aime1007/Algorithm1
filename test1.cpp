#include <iostream>
#include <cstdio>
using namespace std;
int a[105];
int b[105];
int gcd(int a, int b) {
	if(b==0) return a;
	return gcd(b, a%b);
}
int main() {
	int N;
	cin >> N;
	for(int i=0; i<N; i++) {
		scanf("%d/%d", &a[i], &b[i]);
	}
	int sum1=a[0];//总分子 
	int sum2=b[0];//总分母 
	
	for(int i=1; i<N; i++) {
		int t=sum2*b[i]/gcd(sum2, b[i]);//t最小公倍数 
		int fm=b[i]*(t/b[i]);
		int fz=sum1*(t/sum2)+a[i]*(t/b[i]);
		sum1=fz/gcd(fz, fm);
		sum2=fm/gcd(fz, fm);
	}

	int ans=sum1/sum2;
	if(ans!=0) {
		cout << ans;
		if(sum1%sum2!=0) {
			cout<<" "<< sum1%sum2/gcd(sum1, sum2) <<"/"<< sum2/gcd(sum1, sum2);
		}
	}
	else {
		cout << sum1%sum2/gcd(sum1, sum2) <<"/"<< sum2/gcd(sum1, sum2);
	}
} 
