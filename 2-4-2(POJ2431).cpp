#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN=1e4+5;
int N;
int A[MAXN],B[MAXN];
int L, P;
priority_queue<int> que;
int main() {
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> A[i] >> B[i];
	}
	cin >> L >> P;
	
	A[N]=0;
	B[N]=0;
	N++;

	int ans=0, pos=0, tank =P;
	for(int i=0; i<N; i++) {
		int d = L-A[i]-pos;
		while( tank-d<0) {
			if(que.empty()) {
				cout <<"-1";
				return 0;
			}
			tank += que.top(); que.pop();
			ans++;
		}
		tank -= d;
		pos = L-A[i];
		que.push(B[i]);
	}
	cout << ans;
}
