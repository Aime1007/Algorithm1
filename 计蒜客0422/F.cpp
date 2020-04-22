#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 55;
int n,r;
int a[MAXN];
int v[MAXN][MAXN];
int main() {
	int cnt=1;
	while(cin>>n>>r) {
		if(n==0 && r==0) break;
		memset(v,-1,sizeof(v));
		for(int i=1; i<=r; i++) {
			cin>>a[i];
		}
		cout <<"Program "<<cnt<<endl;
		int index=1;
		int count=0;
		for(int i=1,j=1; i<=r; i++,j++) {
			int flag=0;
			for(int k=1; k<index; k++) {
				if(v[j][k]==a[i]) {
					flag=1;
				}
			}
			if(flag==0) {
				cout <<"Page "<<a[i]<<" loaded into cell "<<j<<"."<<endl;
				v[j][index]=a[i];
			}
			else {
				cout <<"Access page "<<a[i]<<" in cell "<<j<<"."<<endl;
				count++;
				j--;
			}
			if(j==n+1) {
				j=1;
				index++;
			}
		}
		cout <<"There are a total of "<<count<<" page faults."<<endl;
	}
}
