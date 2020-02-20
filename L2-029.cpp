#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 10010;
int a,b;
int v[maxn],v2[maxn];
int r[maxn]={0};
int cnt[maxn]={0};
void result(int i) {
	int sum=0,x=i;
	while(1) {
		while(x) {
			sum+=pow(x%10,2);
			x/=10;
		}
		if(v2[i]==1) return;
		if(sum==1) {
			cnt[i]++;
			r[i]=1;
			return;
		}
		if(r[sum]==1) {
			r[sum]=0;
		}
		if(v2[sum]==0) {
			v2[sum]=1;
		}
		if(v[sum]==0) {
			v[sum]=1;
			x=sum;
			sum=0;
			cnt[i]++;
		}
		else return;
	}
	
}
bool IsPrime(int x) {
	for(int i=2; i*i<=x; i++) {
		if(x%i==0) {
			return false;
		}
	}
	return x!=1;
}
int main() {
	cin>> a >> b;
	for(int i=a; i<=b; i++) {
		memset(v,0,sizeof(v));
		result(i);
	} 
	int flag=0;
	for(int i=a; i<=b; i++) {
		if(IsPrime(i)) {
			cnt[i] *= 2;
		}
		if(r[i]==1) {
			cout << i <<" "<< cnt[i] <<endl;
			flag=1;
		}
	}
	if(flag==0) {
		cout <<"SAD";
	}
}
