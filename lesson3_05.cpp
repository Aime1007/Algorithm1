#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1005;
int a[maxn];
int b[maxn];
bool cmp(const int &a, const int &b) {
	return a>b;
}

int main() {
	int n;
    while (cin >> n && n) {
        for (int i=1; i<=n; i++)
            cin >> a[i];
        for (int i=1; i<=n; i++)
            cin >> b[i];
        sort(a+1, a+n+1, cmp);
        sort(b+1, b+n+1, cmp);
        int sa=1,ea=n;
        int sb=1,eb=n;
        int ans=0;
        while(sa<=ea && sb<=eb) {
        	if(a[sa]>b[sb]) {
        		ans++;
        		sa++;
        		sb++;
			}
			else if(a[sa]<b[sb]) {
				ans--;
				ea--;
				sb++;
			}
			else {
				if(a[ea]>b[eb]) {
					ans++;
					ea--;
					eb--;
				}
				else if(a[ea]<b[eb]) {
					ans--;
					ea--;
					sb++;
				}
				else {
					if(a[ea]<b[sb]) {
						ans--;
						ea--;
						sb++;
					}
				}
			}
		}
		cout << ans*200 <<endl;
	}
}
