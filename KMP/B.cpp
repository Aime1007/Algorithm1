#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
const int maxn=1e6+5;
int n,m;
int t[maxn];
int p[maxn];
int Next[maxn];
void makeNext() {
	int q,k;
	int len=strlen(p);
	Next[0]=0;
	for(q=1,k=0; q<len; q++) {
		while(k>0 && p[q]!=p[k]) k=Next[k-1];
		if(p[q]==p[k]) k++;
		Next[q]=k;
	}
}

int kmp() {
	int n,m;
	int i,q;
	n = strlen(t);
	m = strlen(p);
	makeNext();
	for(i=0,q=0; i<n; i++) {
		while(q>0 && p[q]!=t[i]) q=Next[q-1];
		if(p[q]==t[i]) q++;
		if(q==m) 
			return i-m+2;
	}
	return -1;
}
int main() {
	int tt;
	scanf("%d", &tt);
	while(tt--) {
		scanf("%d%d", &n, &m);
		for(int i=0; i<n; i++) {
			scanf("%d", &t[i]);
		}
		for(int i=0; i<m; i++) {
			scanf("%d", &p[i]);
		}
		printf("%d\n", kmp());
	}
	return 0;
}

