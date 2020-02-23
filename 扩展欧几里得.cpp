#include <iostream>
using namespace std;
int exgcd(int a, int b, int &x, int &y) {
	if(b==0) {
		x=1, y=0;
		return a;
	}
	int d=exgcd(b, a%b, x, y);
	int z=x; x=y; y=z-y*(a/b);
	return d;
}
int main() {
	int x,y;
	int ans;
	ans = exgcd(3,6,x,y);
	cout <<"x0 = "<< x <<endl;
	cout <<"y0 = "<< y <<endl;
	cout <<"gcd = "<< ans <<endl;
} 
