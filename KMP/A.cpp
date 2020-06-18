#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
const int maxn=100010;
char s1[maxn];
char s2[maxn];

void makeNext(char p[], int next[]) {
	int q,k;
	int len=strlen(p);
	next[0]=0;
	for(q=1,k=0; q<len; q++) {
		while(k>0 && p[q]!=p[k]) k=next[k-1];
		if(p[q]==p[k]) k++;
		next[q]=k;
	}
}

bool kmp(char t[], char p[], int next[]) {
	int n,m;
	int i,q;
	n = strlen(t);
	m = strlen(p);
	makeNext(p,next);
	for(i=0,q=0; i<m+n; i++) {
		while(q>0 && p[q]!=t[i%n]) q=next[q-1];
		if(p[q]==t[i%n]) q++;
		if(q==m) 
			return true;
	}
	return false;
}
int main() {
	int next[maxn];
	while(~scanf("%s%s",s1,s2)) {
		memset(next,0,sizeof(next));
		int len1=strlen(s1);
		int len2=strlen(s2);
		if(kmp(s1,s2,next)) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}

