#include <iostream>
using namespace std;

int main()
{
	int n,m,k[50];
	int flag=0;
	cin >> n;
	cin >> m; 
	for(int i=0; i<n; i++) {
		cin >> k[i];
	}
	for(int a=0; a<n; a++)
		for(int b=0; b<n; b++)
			for(int c=0; c<n; c++)
				for(int d=0; d<n; d++) {
					if(k[a]+k[b]+k[c]+k[d]==m) {
						flag=1;
					}
				}
	if(flag==0)
		cout<<"No";
	else
		cout<<"Yes";
}
