#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#define min(a,b) (a<b ? a:b)
using namespace std;
const int v[6]={1,5,10,50,100,500};

int c[6];
int a;

int main() {
	for(int i=0; i<6; i++) {
		scanf("%d", &c[i]);
	}
	scanf("%d", &a);
	
	int ans = 0;
	for(int i=5; i>=0; i++) {
		int t=min(a/v[i], c[i]);
		a -= t*v[i];
		ans += t;
	}
	printf("%d\n", ans);
}
