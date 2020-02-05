#include <iostream>
#include <vector>
using namespace std;
vector<int> a;
int main() {
	int n, m;
	while(~scanf("%d %d", &n, &m)) {
		a.clear();
		for(int i=0; i<2*n; i++) {
			a.push_back(i);
		}
		int pos = 0;
		for(int i=0; i<n; i++) {
			pos = (pos+m-1)%a.size();
			a.erase(a.begin()+pos);
		}
		int j = 0;
		for(int i=0; i<2*n; i++) {
			if(!(i%50) && i) cout<<endl;
			if(j<a.size() && i==a[j]) {
				j++;
				cout<<"G";
			}
			else
				cout<<"B";
		}
		cout<<endl<<endl;
	}
	
}
