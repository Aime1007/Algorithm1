#include <iostream>
#include <cstdio>
using namespace std;
int n;
char map[5][5];

int main() {
while(cin >> n) {
	if(n==0) break;	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> map[i][j];
		}
	}
	
	int ans=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(map[i][j]=='.') {
				bool flag=false;
				bool ifwall=false;
				for(int ii=0; ii<n; ii++) {
					if(map[ii][j]=='X') {
						ifwall=true;
					}
					if(map[ii][j]=='0' && ifwall==false) {
						flag=true;
					}
				}
				flag=false;
				ifwall=false;
				for(int jj=0; jj<n; jj++) {
					if(map[i][jj]=='X') {
						ifwall=true;
					}
					if(map[i][jj]=='0' && ifwall==false) {
						flag=true;
					}
				}
				if(flag==false) {
					map[i][j]='0';
					ans++;
				}
			}
		}
	}
	cout << ans <<endl;
}
}
