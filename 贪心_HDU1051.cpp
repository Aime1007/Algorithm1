#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 10005;
struct node {
	int l;
	int w;
}s[MAXN],b[MAXN];

bool cmp(const node &a1, const node &a2) {
	if(a1.l==a2.l) return a1.w<a2.w;
	return a1.l<a2.l;
}
int main() {
	int t; 
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i=1; i<=n; i++) {
			cin >> s[i].l;
			cin >> s[i].w;
		}
		sort(s+1, s+n+1, cmp);
		int index=1;
		for(int i=1; i<=n; i++) {
			int flag=0;
			if(i==1) {
				b[1].l=s[1].l;
				b[1].w=s[1].w;
				continue;
			}
			for(int j=1; j<=index; j++) {
				if(s[i].l>=b[j].l && s[i].w>=b[j].w) {
					b[j].l=s[i].l;
					b[j].w=s[i].w;
					flag=1;
					break;
				}
			}
			if(flag==0) {
				index++;
				b[index].l=s[i].l;
				b[index].w=s[i].w;
			}
		}
		cout << index << endl;
	}
}
