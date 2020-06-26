#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
const int maxn=1e5;
typedef long long ll;
struct node {
	ll x,y;
}z[102];
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		ll x0,y0,ax,ay,bx,by,sx,sy,t;
		scanf("%lld%lld%lld%lld%lld%lld",&x0,&y0,&ax,&ay,&bx,&by);
		scanf("%lld%lld%lld",&sx,&sy,&t);
		int ans=0;
		ll last_x,last_y;
		z[0].x=x0;
		z[0].y=y0;
		ll zz[100];
		for(int i=1; i<=100; i++) {
			z[i].x=ax*z[i-1].x+bx;
			z[i].y=ay*z[i-1].y+by;
			zz[i]=abs(z[i].x-sx)+abs(z[i].y+sy);
		}
		int t=()
		sort()
		for(int i=0; ;i++) {
			if(i==0) {
				if(abs((x0-sx)+(y0-sy))<=t) {
					ans++;
					t-=abs((x0-sx)+(y0-sy));
					last_x=x0;
					last_y=y0;
				}
				else break;
			}
			else {
				ll now_x,now_y;
				now_x=ax*last_x+bx;
				now_y=ay*last_y+by;
				if(abs((now_x-last_x)+(now_y-last_y))<=t) {
					ans++;
					t-=abs((now_x-last_x)+(now_y-last_y));
					last_x=x0;
					last_y=y0;
				}
				else break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

