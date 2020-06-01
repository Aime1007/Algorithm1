#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	while(n--) {
		int cnt=0,flag=0;
		string s;
		cin>>s;
		cout<<s<<endl;
		for(int i=0; i<s.length(); i++) {
			if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') {
				cnt++;
			}
			if(cnt>s.length()/2) {
				flag=1;
			}
		}
		if(flag==1) cout<<1<<endl;
		else cout<<0<<endl;
	}
}
