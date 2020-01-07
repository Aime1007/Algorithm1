#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
char s[2010];
int t[2010];

int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		cin >> s[i];
	}	
	int count=0;
	int a = 0, b = n-1;
	while(a<=b) {
		bool left = false;
		for(int i=0; a+i<=b; i++) {
			if(s[a+i]<s[b-i]) {
				left = true;
				break;
			}
			else if(s[a+i]>s[b-i]) {
				left = false;
				break;
			}
		}
		if(left) putchar(s[a++]);
		else putchar(s[b--]);
		count++;
		if(count%80==0) cout<<endl ;
	}
}
