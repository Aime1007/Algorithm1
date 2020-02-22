#include <iostream>
#include <cstring>
using namespace std;
int v[10000];
void primes(int n) {
	memset(v, 0, sizeof(v));
	for(int i=2; i<=n; i++) {
		if(v[i]) continue;
		cout << i <<endl;
		for(int j=i; j<=n/i; j++) v[i*j]=1;
	}
}
int main() {
	primes(1000);
}
