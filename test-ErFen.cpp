/*
把10本书分成3组，每组厚度之和<=size 
*/
#include <iostream>
using namespace std;
int n=10;
int sum_of_ai=10;
bool valid(int size) {
	int group =1, rest = size;
	for(int i=1; i<=n; i++) {
		if( rest>=a[i]) rest -= a[i];
		else group++, rest = size-a[i];
	}
	return group <= m;
}
int main() {
	int l=0, r=sum_of_ai;
	while(l<r) {
		int mid = (l+r)/2;
		if(valid(mid)) r=mid; else l=mid+1;
	}
	cout << l << endl;
}
