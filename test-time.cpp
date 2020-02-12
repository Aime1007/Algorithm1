#include <iostream>
#include <ctime>
using namespace std;
int data[]={1,2,3,4,5,6,7,8,9,10,32,15,18,33};
int num = 0;
int perm(int begin, int end) {
	int i;
	if(begin == end) {
		num++;
	}
	else {
		for( i=begin; i<=end; i++) {
			swap(data[begin], data[i]);
			perm(begin+1, end);
			swap(data[begin], data[i]);
		}
	}
}
int main() {
	clock_t start, end;
	start = clock();
	perm(0,12);
	end = clock();
	cout <<(double)(end-start)/ CLOCKS_PER_SEC <<endl;
}
