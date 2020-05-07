#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 505*3;
int n,m;
int fa[maxn];
void init() {
	for(int i=0; i<=3*n; i++) {
		fa[i]=i;
	}
}
int get(int x) {
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}
void merge(int x, int y) {
	fa[get(x)]=get(y);
}
bool judge(int x,int y) {
	if(get(x)==get(y)) {
//		printf("%d %d",x,y);
		return true;
	}
	return false;
}
int main() {

	while(~scanf("%d%d", &n, &m)) {
		init();
		int flag=0;
		int num1=-1,num2=-1;
		int Judge=-1;
		int cnt=-1;
		int isans=0;
//		if(n==1) {
//			isans=1;
//		}
		int x,y;
		char ch='=';
		for(int i=1; i<=m; i++) {
			
			scanf("%d%c%d", &x, &ch, &y);
			if(isans==1) continue;
			if(ch=='<') {
				if(judge(x,y) || judge(x+n,y+n) || judge(x+2*n,y+2*n) ||
				judge(x+2*n,y) || judge(x,y+n) || judge(x+n,y+2*n)) {
					if(flag==0) {
						flag=1;
						num1=x; 
						num2=y;
					}
					else {
						if(x==num1 || x==num2) {
							Judge=x;
							cnt=i;
						}
						else if(y==num1 || y==num2) {
							Judge=y;
							cnt=i;
						}
						else Judge=-2;
						isans=1;
					}
				}
				else {
					merge(x,y+2*n);
					merge(x+n,y);
					merge(x+2*n,y+n);					
				}

			}
			else if(ch=='>') {
				if(judge(x,y) || judge(x+n,y+n) || judge(x+2*n,y+2*n) ||
				judge(x,y+2*n) || judge(x+n,y) || judge(x+2*n,y+n)) {
					if(flag==0) {
						flag=1;
						num1=x;
						num2=y;						
					}
					else {
						if(x==num1 || x==num2) {
							Judge=x;
							cnt=i;
						}
						else if(y==num1 || y==num2) {
							Judge=y;
							cnt=i;
						}
						else Judge=-2;
						isans=1;
					}
				}
				else {
					merge(x+2*n,y);
					merge(x,y+n);
					merge(x+n,y+2*n);					
				}
			}
			else {
				if(!judge(x,y) || !judge(x+n,y+n) || !judge(x+2*n,y+2*n)) {
					flag=1;
				}
				else {
					merge(x,y);
					merge(x+n,y+n);
					merge(x+2*n,y+2*n);					
				}
			}
			
		}
		if(n==1) {
			if(ch=='=')
			printf("Player 0 can be determined to be the judge after 0 lines\n");
			else printf("Impossible\n");
			continue;
		}
		//flag==0
		if(Judge==-1) {
			printf("Can not determine\n");
		}
		else {
			if(Judge==-2) printf("Impossible\n");
			else {
				printf("Player %d can be determined to be the judge after %d lines\n", Judge, cnt);
			}
		}
	}
}
