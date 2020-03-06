#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	int a[3];
	int cnt=1;
	cin >> n;
	while(n--) {
		cin>>a[0]>>a[1]>>a[2];		
		cout<<"Data set #"<<cnt<<":"<<endl;
		cout<<"   Original order: "<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
		sort(a,a+3);
		cout<<"   Smallest to largest: "<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl<<endl;
		cnt++;
	}
}
