#include <iostream>
using namespace std;
int n, m, k;
int parent[105];
int e[105][105]={0}; 
void init() {
	for(int i=1; i<=n; i++) {
		parent[i]=i;
	}
}
int find(int x) {
	int r=x;
	while(r!=parent[r]) {
		r=parent[r];
	}
	while(x!=r) {
		int t=parent[x];
		parent[x]=r;
		x=t;
	}
	return r;
}
void merge(int a, int b) {
	a=find(a);
	b=find(b);
	if(a!=b) parent[a]=b;
}
bool judge(int a, int b) {
	if(find(a)==find(b)) return true;
	else return false;
}
int main() {
	cin >> n >> m >> k;
	init();
	while(m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if(c==1) {
			merge(a, b);
		}
		else {
			e[a][b]=1;
			e[b][a]=1;
		}
	}
	
	while(k--) {
		int a, b;
		cin >> a >> b;
		if(judge(a, b) && e[a][b]==0) cout <<"No problem"<<endl;
		else if(!judge(a,b) && e[a][b]==0) cout <<"OK"<<endl;
		else if(judge(a, b) && e[a][b]==1) cout <<"OK but..."<<endl;
		else cout <<"No way"<<endl;
	}
}
