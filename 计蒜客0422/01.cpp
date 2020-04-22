#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 20;
int n,k;
char m[MAXN][MAXN];
int main() {
	int cnt=1;
	while(cin>>n && n) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				cin>>m[i][j];
			}
		}
		cout<<"Input matrix #"<<cnt<<":"<<endl;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<n; j++) {
				cout<<m[i][j]<<" ";
			}
			cout<<m[i][n]<<endl;
		}
		cin>>k;
		for(int t=1; t<=k; t++) {
			int ki;
			cin>>ki;
			cout<<"Symmetric diagonals "<<ki<<":"<<endl;
			int flag=0;
			for(int i=1; i<n; i++) {
				if((ki+i-1)>n){
					break;
				}
				if((ki+i-1)==n) {
					flag=1;
					cout<<m[i][ki+(i-1)]<<endl;
				}
				else cout<<m[i][ki+(i-1)]<<" ";
			}
			if(flag==0)
			cout<<m[n][ki+(n-1)]<<endl;
			
			if(t!=ki) {
				for(int i=1; i<n; i++) {
					if((1-(ki)+i)<1) continue;
					cout<<m[i][1-(ki)+i]<<" ";
				}
				cout<<m[n][1-(ki)+n]<<endl;
			}
			
		}
		cout<<endl;
		cnt++;
	}
}
