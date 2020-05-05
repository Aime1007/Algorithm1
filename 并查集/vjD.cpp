#include <iostream>
#include <cmath> 
using namespace std;
const int maxn = 1005;
int n,d;
struct node {
	double x,y;
}p[maxn];
bool v[maxn];
int root[maxn];
int ready[maxn];
void init() {
	for(int i=1; i<=n; i++) {
		root[i]=i;
		v[i]=false;
	}
} 
int get(int x) {
	if(x==root[x]) return x;
	return root[x]=get(root[x]);
}
void merge(int x,int y) {
	int rx=get(x);
	int ry=get(y);
	double dd=sqrt((p[x].x-p[y].x)*(p[x].x-p[y].x)+(p[x].y-p[y].y)*(p[x].y-p[y].y));
	if(rx!=ry && dd<=d) {
		root[rx]=ry;
	}
}
int main() {
	cin>>n>>d;
	init();
	for(int i=1; i<=n; i++) {
		cin>>p[i].x;
		cin>>p[i].y;
	}
	char ch;
	int x,y,index=0;
	while(cin>>ch>>x) {
		if(ch=='O') {
			v[x]=true;
			ready[index++]=x;
			for(int i=0; i<index-1; i++) {
				merge(ready[i],x);
				//反过来不对 
			}
		}
		else {
			cin>>y;
			if(!v[x] || !v[y] || get(x)!=get(y)) {
				cout<<"FAIL"<<endl;
			}
			else cout<<"SUCCESS"<<endl;
		}
	}
}
