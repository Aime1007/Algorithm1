#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=20;
int a[MAXN];
int n,k;
bool dfs(int i, int sum) {
	if(i == n) return sum==k;
	
	if(dfs(i+1, sum)) return true;
	
	if(dfs(i+1, sum+a[i])) return true;
	
	return false;
}
int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &k);
	
	if(dfs(0,0)) printf("Yes\n");
	else printf("No\n");
}
