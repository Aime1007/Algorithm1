#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll; 
const int MAXN=20050;
int N;
int L[MAXN];
void swap(int *a,int *b) {
	int t=*a;
	*a=*b;
	*b=t;
}
int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		scanf("%d", &L[i]);
	}
	
	ll ans = 0;
	while (N>1) {
		int mii1 = 0, mii2 = 1;
		if(L[mii1]>L[mii2]) swap(mii1, mii2);
		
		for( int i=2; i<N; i++) {
			if(L[i]<L[mii1]) 
		}
	}
	
}
