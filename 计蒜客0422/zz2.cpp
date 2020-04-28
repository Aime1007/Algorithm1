#include <iostream>
using namespace std;
const int MAXN=1005;
int v[MAXN];
int main() {
	int n;
	cin>>n;
	int ans=0,m=0,i=1;
	while(ans<n-1) {
		if(v[i]) {
			i++;
			if(i==n+1) i=1;
			continue;
		}
		m++;
		if(m%3==0) {
			ans++;
			v[i]=1;
		}
		i++;
		if(i==n+1) i=1;
	}
	for(int i=1; i<=n; i++) {
		if(v[i]==0) cout<<i<<endl;
	}
}
