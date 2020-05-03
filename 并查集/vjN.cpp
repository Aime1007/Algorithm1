#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e5+5;
int root[maxn];
int v[maxn];
void init() {
	for(int i=1; i<=1e5; i++) {
		root[i]=i;
		v[i]=0;
	}
}
int get(int x) {
	if(x==root[x]) return x;
	return root[x]=get(root[x]);
}
bool merge(int x,int y) {
	if(x==y) return false;
	x=get(x);
	y=get(y);
	if(x==y) return false;
	root[x]=y;
	return true;
}
int main() {
	int x,y;
	int flag=0;
	int cnt=0;
	while(~scanf("%d%d", &x, &y)) {
		cnt++;
		flag=0;
		if(x==-1 && y==-1) break;
		if(x==0 && y==0) {
            printf("Case %d is a tree.\n", cnt);
            continue;
        }
		init();
		memset(v,0,sizeof(v));       
		v[x]=1;
		v[y]=1;
		if(!merge(x,y)) {
			flag=1;
		}
		while(~scanf("%d%d", &x, &y)) {
			if(x==0 && y==0) break;
			v[x]=1;
			v[y]=1;
			if(!merge(x,y)) {
				flag=1;
			}
		}
		printf("Case %d ", cnt);
		if(flag==1) {
			printf("is not a tree.\n");
			continue;
		}
		int cnt=0;
		for(int i=1; i<=1e5; i++) {
			if(v[i] && root[i] == i) cnt++;
			if(cnt>1) break;
		}
		if(cnt>1) printf("is not a tree.\n");
        else printf("is a tree.\n");
	}
} 
