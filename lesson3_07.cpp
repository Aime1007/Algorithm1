#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 105;
int a[maxn];
int b[maxn];
int main() {
	int n;
	while(cin>>n && n) {
		for(int i=1; i<=n; i++) {
			cin >> a[i];
		}
		for(int i=1; i<=n; i++) {
			cin >> b[i];
		}
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		int ans1=0,ans2=0;
		for(int i=1; i<=n; i++) {
			if(a[i]>b[i]) {
				ans1+=2;
			}
			else if(b[i]>a[i]) {
				ans2+=2;
			}
			else {
				ans1+=1;
				ans2+=1;
			}
		}
		cout<< ans1 <<" vs "<< ans2 <<endl;
	}
}
