#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
const int maxn=1e5;

int main() {
	int n,m;
	vector<int> a;
	a.push_back(-1);
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++) {
		int t;
		scanf("%d", &t);
		a.push_back(t);
	} 
	for(int i=0; i<m; i++) {
		int t;
		scanf("%d", &t);
		if(t==1) {
			int k;
			scanf("%d", &k);
			vector<int>::iterator it=a.begin()+k;
			a.erase(it);
		}
		else {
			int l,r;
			scanf("%d%d", &l, &r);
			int min=l,max=l;
			for(int i=l; i<=r; i++){
				if(a[i]<a[min]) min=i;
				if(a[i]>a[max]) max=i;
				//cout<<a[i]<<endl;
			}
			printf("%d %d\n",a[min],a[max]);
		}
	}
	return 0;
}

