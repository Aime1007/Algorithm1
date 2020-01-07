#include <iostream>
#include <stdio.h>
#define max(a,b) (a>b ? a:b)
#define min(a,b) (a<b ? a:b) 
const int MaxN=1e6;
using namespace std;
int L,n;
int x[MaxN];
int main() {
	int t;
	scanf("%d", &t);
	for(int i=0; i<t; i++) {
		scanf("%d", &L);
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			scanf("%d", &x[i]);
		}
		
		int minT = 0;
		for(int i=0; i<n; i++) {
			minT = max(minT,min(x[i],L-x[i]));
		}
		
		int maxT = 0;
		for(int i=0; i<n; i++) {
			maxT = max(maxT, max(x[i], L-x[i]));
		}
		
		printf("%d %d\n", minT, maxT);
	}
}
