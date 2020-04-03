#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1005;
struct node {
	int data;
	bool v;
}a[maxn],b[maxn];
bool cmp(const node &a1, const node &a2) {
	return a1.data>a2.data;
}
int main() {
	int n;
	while(cin>>n && n) {
		int ans=0;
		for(int i=1; i<=n; i++) {
			cin >> a[i].data;
			a[i].v=false;
		}
		for(int i=1; i<=n; i++) {
			cin >> b[i].data;
			b[i].v=false;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		int index=n;
		for(int i=1; i<=n; i++) {
			if(a[i].data<b[i].data) {
				int flag=0;
				for(int j=i-1; j>=1; j--) {
					if(j<1) break;
					if(a[j].v=false) {
						if(a[j].data>b[i].data) {
							a[j].v=true;
							b[i].v=true;
							flag=1;
							break;
						}
					}
				}
				if(flag==0) {
					int flag2=0;
					for(int j=n; j>i; j--) {
						if(a[j].v=false) {
							a[j].v=true;
							b[i].v=true;
							flag2=1;
							break;
						}
					}
					if(flag2==0) ans++;
				}
			}
			else if(a[i].data>=b[i].data){
				int index=-1;
				for(int j=i+1; j<=n; j++) {
					if(j>n) break;
					if(a[j].v=false) {
						if(a[j].data>b[i].data) {
							index=j;
						}
						else break;
					}
				}
				if(index!=-1) {
					a[index].v=true;
					b[i].v=true;
				}
				else {
					a[i].v=true;
					b[i].v=true;
				}
			}
		}
		cout << ans*200 <<endl;
	}
}
