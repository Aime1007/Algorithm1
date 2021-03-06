#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
const int maxn=1e5;
char t[maxn];
char p[maxn];
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
			printf("Pattern occurs with shift:%d\n",(i-m+1));
	}
}
int main() {
	memset(Next,0,sizeof(Next));
	//scanf("%s%s", t, p); 
	gets(t);
	gets(p);
	//BBC ABCDAB ABCDABCDABDE
	//c
	kmp();
	for(int i=0; i<strlen(p); i++) {
		printf("%d ",Next[i]);
	}
	return 0;
}

