#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
const int maxn=1e6+5;
char s[maxn];
int Next[maxn];
int len;
void GetNext() {
	int i=0,j=-1;
	Next[0]=-1;
	while(i<len) {
		if(j == -1 || s[i] == s[j]) {
			i++;
			j++;
		   	Next[i] = j;
		}
		else j = Next[j];
	}
}
int main() {
	int t=0;
	while(~scanf("%d", &len)) {
		if(len==0) break;
		scanf("%s", s);
		GetNext();
		printf("Test case #%d\n", ++t);
		for(int i=2; i<=len; i++) {
			if(i%(i-Next[i])==0&&i/(i-Next[i])>1) {
				printf("%d %d\n", i, i/(i - Next[i]));
			}
		}
		cout<<endl;
	}
	return 0;
}

