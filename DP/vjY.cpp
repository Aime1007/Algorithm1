#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e5+5;
int n,m;
int dp[maxn][12];
struct node {
	int x;
	int t;
}a[maxn];
bool cmp(node &a1,node &a2) {
	return a1.t<a2.t;
}
void solve() {
	for(int i=1; i<=m; i++) {
		for(int j=0; j<=10; j++) {
			if(abs(5 - j) > i) dp[i][j]=0;
			else {
				if(i == 0)
				dp[i][j] += max(dp[i-1][j+1], dp[i-1][j]);
			else if(i == 10)
				dp[i][j] += max(dp[i-1][j], dp[i-1][j-1]);
			else if(i > 0 && i < 10)
				dp[i][j] += max(max(dp[i-1][j-1], dp[i-1][j+1]), dp[i-1][j]);
			}
			
		}
	}
}
int main() {
	while(~scanf("%d", &n) && n) {
		memset(dp,0,sizeof(dp));
		for(int i=1; i<=n; i++) {
			int x,t;
			scanf("%d%d",&x ,&t);
			a[i].x=x;
			a[i].t=t;
		}
		sort(a+1,a+n,cmp);
		m=0;
		for(int i=1; i<=n; i++) {
			if(a[i].t>a[i-1].t) {
				m=a[i].t;
			}
			if(dp[a[i].t-1][a[i].x]==0&&dp[a[i].t-1][a[i].x-1]==0&&dp[a[i].t-1][a[i].x+1]==0) {
				if(a[i].x!=4 && a[i].x!=5 && a[i].x!=6) continue;
			}
			dp[a[i].t][a[i].x]+=1;
		}
		solve();
		int ans=0;
		for(int i=1; i<=m; i++) {
			for(int j=0; j<=10; j++) {
				if(dp[i][j]>ans) ans=dp[i][j];
			}
		}
		cout<< ans <<endl;
	}
}
