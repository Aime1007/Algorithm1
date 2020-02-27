#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int n;
	int m[105];
	int v[105];
	int a[105][105];
	int count[105];
	memset(v,0,sizeof(v));
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> m[i];
	}
	int max=0;
	for(int i=1; i<=n; i++) {
		max += m[i]*10;
	}
	int cnt=0, j=1;
	for(int i=1; i<=n; i++) {
		int flag=0;
		for(int k=1; k<=n; k++) {
			if(v[k]==1) flag++;
		}
		if(v[i]==0) {
			cnt++;
			if(flag==n-1) a[i][j]=a[i][j-1]+2;
			else a[i][j]=cnt;
			count[i]++;
		}
		if(count[i]==m[i]*10) {
			v[i]=1;
		}
		if(cnt==max) break;
		if(i==n) {
			i=0;
			j++;
		}
	}
	for(int i=1; i<=n; i++) {
		cout <<"#"<<i<<endl;
		for(int j=1; j<=m[i]*10; j++) {
			cout << a[i][j];
			if(j%10!=0) cout<<" ";
			else cout <<endl;
		}
	}
} 
