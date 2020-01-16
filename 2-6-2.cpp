#include <iostream>
using namespace std;
const int MAXN=1e6+5;
int prime[MAXN];
bool isprime[MAXN];

int main() {
	int n;
	cin >> n;
	int p = 0;
	for(int i=0; i<=n; i++) isprime[i] = true;
	isprime[0] = false; 
	isprime[1] = false;
	for(int i=2; i<=n; i++) {
		if(isprime[i]) {
			prime[p++] = i;
			for(int j=i*2; j<=n; j+=i) {
				isprime[j] = false;
			}
		}
	}
	cout << p;
} 
