#include <iostream>
using namespace std;
int dp[100];
//递归---自顶向下 
int fib(int n) {
	if(n==0 || n==1) return 1;
	return fib(n-1)+fib(n-2);
}

int fib2(int n) {
	if(dp[n]<0) {
		dp[n]=fib2(n-1)+fib2(n-2);
	}
	return dp[n];
}
//递推----自底向上 O（n）高效 
int fib3(int n) {
	for(int i=2; i<n; i++) {
		dp[i]=dp[i-1]+dp[i-2];
	}
	return dp[n];
}
int main() {
	dp[0]=dp[1]=1;
	for(int i=2; i<10; i++) {
		dp[i]=-1;
	}
	
	cout<<fib(6)<<endl;
	cout<<fib2(6)<<endl;
	cout<<fib3(6)<<endl;
}
