#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN=1e4+5;
int N;
struct Node {
	int a,b;
}A[MAXN];
int L, P;
priority_queue<int> que;
bool cmp(const Node &a1,const Node &a2)
{
	return a1.a>a2.a;
}

int main() {
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> A[i].a >> A[i].b;
	}
	cin >> L >> P;
	
	A[N].a=0;
	A[N].b=0;
	N++;
	sort(A,A+N,cmp);
	int ans=0, pos=0, tank =P;
	for(int i=0; i<N; i++) {
		int d = L-A[i].a-pos;
		while( tank-d<0) {
			if(que.empty()) {
				cout <<"-1";
				return 0;
			}
			tank += que.top(); que.pop();
			ans++;
		}
		tank -= d;
		pos = L-A[i].a;
		que.push(A[i].b);
	}
	cout << ans;
}
