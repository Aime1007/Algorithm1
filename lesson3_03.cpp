#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 105;
struct node {
	int s;
	int e;
}a[maxn];
bool cmp(const node &a1,const node &a2) {
	return a1.e<a2.e;
}
int main() {
	int n;
	while(cin >> n) {
		if(n==0) break;
		int ans=1;
		for(int i=1; i<=n; i++) {
			int s,e;
			cin >> a[i].s >> a[i].e;
		}
		sort(a+1,a+n+1,cmp);
		int flag=1;
//		if(n==1) {
//			cout << 1 <<endl;
//			continue;
//		}
		for(int i=2; i<=n; i++) {
			if(a[i].s>=a[flag].e) {
				flag=i;
				ans++;
			}
		}
		cout << ans <<endl;
	}
}
