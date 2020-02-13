#include <iostream>
#include <ctime>
using namespace std;
int data[]={1,2,3,4,5,6,7,8,9,10,32,15,18,33};
int num = 0;
int cnt = 0;
int perm(int begin, int end) {
	int i;
	cnt ++;
	cout<<"cnt = "<<cnt<<endl;
	cout<<"perm("<<begin<<","<<end<<")"<<endl;
	if(begin == end) {
		for(int i=0; i<=begin; i++) {
			cout<<data[i];
		}
		cout<<endl;
		num++;
	}
	else {
		for( i=begin; i<=end; i++) {
			swap(data[begin], data[i]);
//			cout<<"1swap(data["<<begin<<"], data["<<i<<"]);"<<endl;
//			for(int j=0; j<=begin; j++) {
//				cout<<data[j];
//			}
//			cout<<endl;
			perm(begin+1, end);
			
			swap(data[begin], data[i]);
//			cout<<"2swap(data["<<begin<<"], data["<<i<<"]);"<<endl;
//			for(int j=0; j<=begin; j++) {
//				cout<<data[j];
//			}
//			cout<<endl;
		}
	}
}
int main() {
	clock_t start, end;
	start = clock();
	perm(0,2);
	end = clock();
	cout <<(double)(end-start)/ CLOCKS_PER_SEC <<endl;
	cout <<num;
}
