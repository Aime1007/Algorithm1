#include <iostream>
#include <cstring> 
using namespace std;
int N,V;
struct node {
	int val;
	int vol;
}b[1005];
//�������飬�µ�һ�и���ԭ����һ�� 
int dp[1005];
int solve() {
	memset(dp,0,sizeof(dp));
	for(int i=1; i<=N; i++) {
		//�Ӻ���ǰ�������Ӻ���ǰ���ǣ�����Ӱ���� 
		for(int j=V; j>=b[i].vol; j--) {
			dp[j] = max(dp[j],dp[j-b[i].vol]+b[i].val);
		}
	}
	return dp[V];
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> N >> V;
		for(int i=1; i<=N; i++) cin >> b[i].val;
		for(int i=1; i<=N; i++) cin >> b[i].vol;
		cout << solve() << endl;
	}
}
