#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 205;
struct node {
	int s;
	int e;
}a[maxn];
int s[maxn];
bool cmp(const node &a1, const node &a2) {
	return a1.s<a2.s;
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i=1; i<=n; i++) {
			cin >> a[i].s >> a[i].e;
		}
		for(int i=1; i<=n; i++) {
			if(a[i].s>a[i].e) {
				swap(a[i].s,a[i].e);
			}
		}
		sort(a+1,a+n+1,cmp);
		int cnt=1;
		for(int i=1; i<=n; i++) {
			if(i==1) {
				s[i]=a[i].e;
				continue;
			}
			int flag=0;
			for(int j=1; j<=cnt; j++) {
				if(s[j]%2==0 && a[i].s>s[j])  {
					s[j]=a[i].e;
					flag=1;
					break;
				} 
				else if(s[j]%2!=0 && a[i].s>s[j]+1) {
					s[j]=a[i].e;
					flag=1;
					break;
				}
			}
			if(flag==0) {
				cnt++;
				s[cnt]=a[i].e;
			}
		}
		cout << cnt*10 << endl;
	}
}
