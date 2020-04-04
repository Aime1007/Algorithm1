#include <iostream>
using namespace std;
const int MONEY = 251;
const int VALUE = 5;
int type[VALUE] = {1,5,10,25,50};
int Min[MONEY];
int path[MONEY]={0};
void solve() {
	for(int i=0; i<MONEY; i++) {
		Min[i]=INT_MAX;
	}
	Min[0]=0;
	for(int i=0; i<VALUE; i++) {
		for(int j=type[i]; j<MONEY; j++) {
			if(Min[j]>Min[j-type[i]]+1) {
				path[j]=type[i];
				Min[j]=Min[j-type[i]]+1;
			}
		}
	}
}
int main() {
	int s;
	solve();
	while(cin>>s) {
		cout << Min[s] <<endl;
		while(s) {
			cout << path[s] <<" ";
			s=s-path[s];
		}
		cout<<endl; 
	}
}
