#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 1000;
int m;
int p[maxn],c[maxn];
void divide(int n) {
	m=0;
	for(int i=2; i<=sqrt(n); i++) {
		if(n%i==0) {
			p[++m]=i, c[m]=0;
			while(n%i==0) n/=i, c[m]++; 
		}
	}
	if(n>1) p[++m]=n,c[m]=1;
	for(int i=1; i<=m; i++) {
		cout << p[i] <<"^"<< c[i] <<endl;
	}
}
int main() {
	divide(12);
}
