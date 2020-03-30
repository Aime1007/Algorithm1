#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1005;
struct node {
	int f;
	int j;
	double v;
}a[maxn];
bool cmp(const node &a1,const node &a2) {
	return a1.v>a2.v;
}
int main() {
	int m,n;
	while(cin >> m >> n) {
		if(m==-1 && n==-1) break;
		double ans=0;
		for(int i=1; i<=n; i++) {
			cin >> a[i].j >> a[i].f;
			a[i].v=1.0*a[i].j/a[i].f;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1; i<=n; i++) {
			if(a[i].f<=m) {
				ans+=a[i].j;
				m-=a[i].f;
			}
			else {
				double s=1.0*a[i].j/a[i].f;
				ans+=s*m;
				m=0;
			}
			if(m==0) break;
		}
		printf("%.3f\n", ans);
	}
}
