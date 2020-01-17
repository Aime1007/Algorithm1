#include <iostream>
#include <cstring>
#define max(a,b) (a>b ? a:b)
using namespace std;

int a[10];
int N;
bool rec(int i, int s) {
	if(i ==0) {
		return a[0]==s;
	}
	else if( s==0) {
		return true;
	}
	else if(a[i]>s) {
		return rec(i-1, s);
	}
	else {
		return (rec(i-1, s-a[i]) || rec(i-1, s));
	}
}
int main() {
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> a[i];
	}
	
	if(rec(5,9))
		cout << "true";
	else 
		cout << "false";
}
