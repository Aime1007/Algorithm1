#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 105;
struct node {
	int p,h;
}a[maxn];
bool cmp(const node &a1, const node &a2) {
	return a1.p<a2.p;
}
int main() {
	int c;
	cin >> c;
	while(c--) {
		int n,m;
		cin >> n >> m;
		for(int i=1; i<=m; i++) {
			cin >> a[i].p >> a[i].h;
		}
		sort(a,a+m+1,cmp);
		double ans=0;
		for(int i=1; i<=m; i++) {
			if(n>=a[i].p*a[i].h) {
				ans+=a[i].h;
				n-=a[i].p*a[i].h;
			}
			else {
				ans+=1.0*n/a[i].p;
				break;
			}
		}
		printf("%.2f\n", ans);
	}
}
