#include <iostream>
#define max(a,b) (a>b ? a:b)
using namespace std;

int a[10];
int N;
int rec(int i) {
	if( i==0) {
		return a[0];
	}
	else if( i==1) {
		return max(a[0], a[1]);
	}
	else {
		return max(rec(i-2)+a[i], rec(i-1));
	}
}
int main() {
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> a[i];
	}
	
	cout <<rec(N);
} 
