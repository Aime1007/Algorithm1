#include <iostream>
using namespace std;
const int maxn = 1005;

struct node {
	int x,y;
}p[maxn];
int root[maxn];
int main() {
	int n,d;
	cin>>n>>d;
	for(int i=1; i<=n; i++) {
		cin>>p[i].x;
		cin>>p[i].y;
	}
	char ch;
	while(cin>>ch) {
		if(ch=='O') {
			int c;
			cin>>c;
			root[c]=1;
		}
	}
}
