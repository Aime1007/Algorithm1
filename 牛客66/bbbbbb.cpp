#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
const int maxn=1e5;

int main() {
	int n,ans=0,l,r;
	int a[20];
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d%d",&l,&r);
	for(int i=l; i<=r; i++){
		if(i%8==0) {
			int flag=0;
			for(int i=0; i<n; i++) {
				if(i%a[i]==0) {
					flag=1;
					break;
				}
			}
			if(flag==0) ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}

