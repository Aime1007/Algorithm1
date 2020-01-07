#include <iostream>
#include <algorithm>
#define max(a,b) (a>b ? a:b)
#define min(a,b) (a<b ? a:b) 
using namespace std;
int main()
{
	int n;
	int k[105];
	int flag = 0;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> k[i];
	}
	int a1,b1,c1;
	int max = 0;
	for(int a=0; a<n; a++)
		for(int b=0; b<n; b++)
			for(int c=0; c<n; c++) {
				if(k[a]*k[a]+k[b]*k[b]==k[c]*k[c]) {
					flag = 1;
					if(k[a]+k[b]+k[c]>max) {
						a1=k[a];
						b1=k[b];
						c1=k[c];
					}
				}
			}
	if(flag==binary_search(k,k+10,10))
		cout << a1+b1+c1;
	else 
		cout <<"0";
	
}
