#include <iostream>
#include <cmath>
using namespace std;
const int maxn= 1e3;
int f[maxn][maxn];
int a[6]={0,5,2,1,6,7};
int n=5;
void ST() {
	for(int i=1; i<=n; i++) {
		f[i][0]=a[i];
	}
	int t=log(n)/log(2)+1;
	for(int j=1; j<t; j++) {
		for(int i=1; i<=n-(1<<j)+1; i++) {
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		}
	}
}
int main() {
	ST();
	cout<<f[1][1];
}
