#include <iostream>
#include <queue>
using namespace std;
int n;
int map[380][20];
struct Node {
	int x,y;
};
queue<Node> q;
int main() {
	while(cin>>n) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=16; j++) {
				cin >> map[i][j];
			}
		}
	}
	Node start;
	start.x=2; start.y=2;
	q.push(start);
}
