#include <iostream>
using namespace std;
int n;
int p[100]; 

perm2(int m) {
	if(m==0) {
		for(int i=0; i<n; i++) {
			cout << p[i];
		}
		cout<<endl;
	}
	else {
		for(int j=0; j<n; j++) {
			if(p[j]==0) {
				p[j]=m;
				perm2(m-1);
				p[j]=0;
			}
		}
	}
}
int main() {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> p[i];
	}
	perm2(n-1); 
}
