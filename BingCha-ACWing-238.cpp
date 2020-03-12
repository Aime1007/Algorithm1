#include <iostream>
using namespace std;
const int maxn=3e4+5;
int root[maxn];
int cnt=0;
void init() {
	for(int i=1; i<=maxn; i++) {
		root[i]=i;
	}
}
int find(int x) {
	cnt=0;
	while(x!=root[x]) {
		x=root[x];
		cnt++;
	}
	return x;
}
void merge(int x,int y) {
	root[find(x)]=find(y);
}
int main() {
	init();
	int t;
	cin >> t;
	while(t--) {
		char c;
		int x,y;
		cin >> c >> x >> y;
		if(c=='M') merge(x,y);
		else {
			if(find(x)!=find(y)) cout<<-1<<endl;
			else {
				find(x);
				int x=cnt;
				find(y);
				int y=cnt;
				cout<<max(x,y)-1<<endl;
			}
		}
	}
} 
