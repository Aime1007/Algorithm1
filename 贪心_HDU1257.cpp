#include <iostream>
#include <vector>
using namespace std;
vector<int> a;
int main() {
	int n;
	while(cin>>n) {
		a.clear();
		a.push_back(30005);
		for(int i=1; i<=n ;i++) {
			int now;
			cin>>now;
			int flag=0;
			for(int j=0; j<a.size(); j++) {
				if(now<=a[j]) {
					flag=1;
					a[j]=now;
					break;
				}
			}
			if(flag==0) {
				a.push_back(now);
			}
		}
		cout << a.size() << endl;
	}
}
