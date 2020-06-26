#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
const int maxn=1e5;
int h,n,m;
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d", &h, &n, &m);
		int flag=0;
		const int hh=h;
		m*=10;
		for(int i=n; i>=0; i--){
			if(m>=h) {
				flag=1; break;
			}
			h=h/2+10;
		}
		if(m>=hh) flag=1;
		if(flag==1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

