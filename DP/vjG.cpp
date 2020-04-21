#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 32;
float q;
int n,index;
int val[MAXN];
int dp[5050000];
void solve() {
	for(int i=1; i<index; i++) {
		for(int j=(int)(q*100); j>=val[i]; j--) {
			dp[j]=max(dp[j],dp[j-val[i]]+val[i]); 
		}
	}
}
int main() {
	while(cin>>q>>n) {
		if(n==0) break;
		memset(val,0,sizeof(val));
		memset(dp,0,sizeof(dp));
		index=1;
		for(int i=1; i<=n; i++) {
			int m;
			cin>>m;
			int flag=0,sum=0,suma=0,sumb=0,sumc=0;
			for(int j=1; j<=m; j++) {
				char c,c1;
				float v;
				cin>>c>>c1>>v;
				v*=100;
//				cout <<"v: "<<v<<endl;
				if(c=='A') suma+=v;
				else if(c=='B') sumb+=v;
				else if(c=='C') sumc+=v;
				else {
					flag=1;
					break;
				}
				if(suma>60000||sumb>60000||sumc>60000) {
					flag=1;
					break;
				}
//				cout <<"sum: "<<sum<<endl;
			}
			sum=suma+sumb+sumc;
			if(flag==0&&sum<=100000) {
				val[index++]=sum;
			}
		}
//		for(int i=1; i<index; i++) cout <<val[i]<<endl;
		solve();
		printf("%.2f\n", 1.0*dp[(int)(q*100)]/100);
	}
} 
