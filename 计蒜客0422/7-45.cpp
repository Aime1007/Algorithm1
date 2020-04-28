#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<string,int> h;
int main() {
	int n,k;
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		char s[17];
		int val;
		scanf("%s%d",s,&val);
		if(val<k) val=k;
		h[s]+=val;
	}
	int m;
	cin>>m;
	for(int i=1; i<=m; i++) {
		string s;
		cin>>s;
		if(!h[s]) printf("No Info\n");
		else printf("%d\n",h[s]);
	}
}
