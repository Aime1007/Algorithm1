#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#define min(a,b) (a<b ? a:b)
using namespace std;
int n;
char s[2500];

int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%c", &s[i]);
	}
	
	int a = 0, b = n-1;
	while (a<=b) {
		bool left =false;
		for(int i=0; a+i<=b; i++) {
			if( s[a+i] < s[b-i]) {
				left =true;
				break;
			}
			else if( s[a+i] > s[b-i]) {
				left =false;
				break;
			}
		}
		if(left) putchar(s[a++]);
		else putchar(s[b--]);
	}


	
	cout<<endl;
}
