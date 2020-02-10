#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<queue>
#include<bitset>
#include<list>
#include<stack>
#include<iterator>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
int step[100];
int cnt=1;
bool flag=false; //��û�ѵ���� 
int n;
void iddfs(int sep) {
	if( sep>cnt) {
		if(step[sep-1]==n) {
			flag=true;
		}
		return ;
	}
	for(int i=sep-1; i>0; i--) {
		for(int j=i; j>0; j--) {
			if(step[i]+step[j]<=n && step[i]+step[j]>step[sep-1] && !flag) {
				step[sep]=step[i]+step[j];
				iddfs(sep+1);
			}
		}
	}
}

int main() {
	while( cin >>n&&n) {
		int k=1;  //��ǰ����� 
		cnt=1;
		flag=false;
		while(k<n) { //���ٴ�����һ�� 
			k <<=1;
			cnt++;
		}
		step[1]=1;
		for(; !flag; cnt++) {
			iddfs(2);
		}
		
		for(int i=1; i<cnt; i++) {
			cout << step[i] <<" ";
		}
		cout<<endl;
	}
}
