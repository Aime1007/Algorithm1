#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1005;
int a[maxn];
bool cmp(const int &a1, const int &a2) {
	return a1>a2;
}
int main() {
	int t;
	cin >> t; 
	while(t--) {
		int n;
		cin >> n;
		for(int i=1; i<=n ;i++) {
			cin >> a[i];
		}
		if(n==1) {
			if(a[1]==0) cout <<"yes"<<endl;
			else cout <<"no"<<endl;
			continue;
		}
		sort(a+1, a+n+1, cmp);
		int flag=0;
		while(a[1]>0) {
			int cnt=0;
			for(int i=2; i<=n; i++) {
				if(a[i]-1>=0) {
					a[i]=a[i]-1;
					cnt++;
				}
				else {
					flag=1;
					break;
				}
				if(cnt==a[1]) {
					break;
				}
			}
			a[1]=0;
			if(flag==1) break;
			sort(a+1,a+n+1, cmp);
		}
		if(flag==0) cout <<"yes"<< endl;
		else cout <<"no"<< endl;
	}
} 
