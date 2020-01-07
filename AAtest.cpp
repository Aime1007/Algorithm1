#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	priority_queue<int,vector<int>, greater<int> > q;
	q.push(5);
	q.push(4);
	q.push(44);
	q.push(2);
	q.push(43);
	while(!q.empty()) {
		cout << q.top() <<endl;
		q.pop();
	}
	return 0;
}
