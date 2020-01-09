#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN=1050;
int n;
int R;
int x[MAXN];

int main() {
	scanf("%d", &n);
	scanf("%d", &R);
	for(int i=0; i<n; i++) {
		scanf("%d", &x[i]);
	}
	
	sort(x,x+n);
	int i=0, ans = 0;
	while(i<n) {
		int s = x[i++];
		while(i<n && x[i]<=s+R) i++;
		
		int p = x[i-1];
		
		while(i<n && x[i]<=p+R) i++;
		
		ans++;
	}
	cout << ans;
}
