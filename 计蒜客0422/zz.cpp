#include <iostream>
#include <queue>
using namespace std;
int n;
queue<int> q;
int main() {
	cin>>n;
	for(int i=1; i<=n; i++) {
		q.push(i);
	}
	int cnt=0;
	while(q.size()>1) {
		cnt++;
		int p=q.front();
		q.pop();
		if(cnt!=3) q.push(p);
		else cnt=0;
	}
	cout << q.front() <<endl;
}
