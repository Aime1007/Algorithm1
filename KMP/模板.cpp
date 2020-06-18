#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
const int maxn=1e5;
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

int kmp(char t[], char p[], int next[]) {
	int n,m;
	int i,q;
	n = strlen(t);
	m = strlen(p);
	makeNext(p,next);
	for(i=0,q=0; i<n; i++) {
		while(q>0 && p[q]!=t[i]) q=next[q-1];
		if(p[q]==t[i]) q++;
		if(q==m) 
			printf("Pattern occurs with shift:%d\n",(i-m+1));
	}
}
int main() {
	int next[20]={0};
	char t[]="BBC ABCDAB ABCDABCDABDE";
	char p[]="ABCDABD";
	kmp(t,p,next);
	for(int i=0; i<strlen(p); i++) {
		printf("%d ",next[i]);
	}
	return 0;
}

