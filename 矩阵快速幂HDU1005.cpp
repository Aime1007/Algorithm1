#include <iostream>
#include <cstring>
#define ll long long
using namespace std;
struct mat {
	ll a[2][2];
	mat() {
		memset(a,0,sizeof(a));
	}
};
mat mul(mat x,mat y) {
	mat ans;
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			for(int k=0; k<2; k++) {
				ans.a[i][j]=(ans.a[i][j]+(x.a[i][k]*y.a[k][j])%7)%7;
			}
		}
	}
	return ans;
}
void quickpow(int a,int b,int k) {
	mat ans,x;
	x.a[0][0]=a; x.a[0][1]=b;
	x.a[1][0]=1; x.a[1][1]=0;
	ans.a[0][0]=ans.a[1][1]=1;
	while(k) {
		if(k&1){
			ans=mul(ans,x);
		}
		k>>=1;
		x=mul(x,x);
	}
	int sum=(ans.a[0][0]+ans.a[0][1])%7;
	cout << sum <<endl;
}

int main() {
	int a,b,n;
	while(cin>>a>>b>>n) {
		if(a==0 && b==0 && n==0) break;
		if(n==1 || n==2) {
			cout <<"1"<<endl;
		}
		else quickpow(a,b,n-2);
	}
}
