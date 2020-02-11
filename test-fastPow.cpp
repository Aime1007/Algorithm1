#include <iostream>
using namespace std;
//int fastPow(int a, int n) {
//	if(n == 1) return a;
//	int temp = fastPow(a, n/2);
//	if(n%2 == 1)
//		return temp * temp *a;
//	else 
//		return temp * temp;
//}

//int fastPow(int a, int n) {
//	int res = 1;
//	while(n) {
//		if(n&1)
//			res *= a;
//		a *= a;
//		n >>=1;
//	}
//	return res;
//}
const int mod = 200907;
int fastPow(int a, int n) {
	int res = 1;
	while(n) {
		if(n&1)
			res = (res*a)%mod;
		a = (a*a)%mod;
		n >>=1;
	}
	return res;
}
int main() {
	
}
