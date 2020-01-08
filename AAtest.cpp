#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#define min(a,b) (a<b ? a:b)
using namespace std;
int n;
int t[2500];
void find(int left,int right) {
		if( left < right ) {
			t[i]=s[left];
			left ++;
		}
		else if( left > right ) {
			t[i]=s[right];
			right --;
		}
		else {
			
		}
	}
int main() {
	string s;
	scanf("%d", &n);
	scanf("%d", &s);
	
	int left = 0, right = s.length()-1;
	

	
	int ans=0, tt=0;
	for(int i=0; i<n; i++) {
		if( tt<item[i].second) {
			ans ++;
			tt=item[i].first;
		}
	}
	
	cout << ans <<endl;
}
