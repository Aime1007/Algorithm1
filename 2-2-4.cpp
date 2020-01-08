#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN=1050;
int n;
int R;
int a[MAXN];

int main() {
	scanf("%d", &n);
	scanf("%d", &R);
	for(int i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	
	int r=a[0], count=0;
	for(int i=0; i<n; i++) {
		if(a[i]-r>R) {
			count++;
			r=a[i];
		}
	}
	printf("%d", count);
}
