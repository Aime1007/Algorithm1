#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=1005;
int N,M;
struct Node {
	double J,F;
	double b;
}A[MAXN];
bool cmp(const Node &a1,const Node &a2)
{
	return a1.b>a2.b;
}
int main() {
while(cin >> M >> N) {
	if(N==-1 && M==-1) break;
	for(int i=0; i<N; i++) {
		cin >> A[i].J >> A[i].F;
		A[i].b = A[i].J/A[i].F;
	}
	
	sort(A,A+N,cmp);
	double ans=0;
	double m=M;
	for(int i=0; i<N; i++) {
		
		if(m-A[i].F>=0) {
			ans+=A[i].J;
			m-=A[i].F;
		}
		else if (m-A[i].F<0){
			ans+=(m/A[i].F)*A[i].J;
			m=0;
		}
		if(m==0) break;
	}
	
	printf("%.3f\n", ans);
}
}
