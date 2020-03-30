#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int t;
	cin >> t;
	for(int k=1; k<=t; k++) {
		string s;
		cin >> s;
		int ans=INT_MAX;
		int flag=0;
		for(int i=0; i<s.length()-1; i++) {
			for(int j=i+1; j<s.length(); j++) {
				if(s[i]==s[j] && j-i<ans) {
					ans=j-i;
					flag=1;
				}
			}
		}
		if(flag==0) ans=-1;
		cout <<"Case #"<<k<<": "<< ans <<endl;
	}
}
