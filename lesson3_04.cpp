#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1005;
struct node {
	int dead;
	int rdu;
	bool v;
}a[maxn];
bool cmp(const node &a1, const node &a2) {
	return a1.dead<a2.dead;
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i=1; i<=n; i++) {
			cin >> a[i].dead;
		}
		for(int i=1; i<=n; i++) {
			cin >> a[i].rdu;
			a[i].v=false;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1,day=1; i<=n; i++,day++) {
			if(day<=a[i].dead) {
				a[i].v=true;
			}
			else {
				int min=-1;
				for(int j=1; j<i; j++) {
					if(a[j].v==true) {
						min=j;
						break;
					}
				}
				if(min==-1) continue;
				for(int j=1; j<i; j++) {
					if(a[j].rdu<a[min].rdu && a[j].v==true) {
						min=j;
					}
				}
				if(a[min].rdu<a[i].rdu) {
					a[min].v=false;
					a[i].v=true;
					day--;
				}
			}
		}
		int ans=0;
		for(int i=1; i<=n; i++) {
			if(a[i].v==false) {
				ans+=a[i].rdu;
			}
		}
		cout << ans << endl;
	}
}
