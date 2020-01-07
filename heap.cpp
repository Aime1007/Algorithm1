#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio> 
using namespace std;
const int MAXN=1e6;
int heap[MAXN];
int size=0;
void push(int x) {
	int i=size++;
	while(i>0) {
		int p=(i-1)/2;
		if(heap[p]<heap[i]) {
			break;
		}
		heap[i]=heap[p];
		i = p;
	}
	heap[i]=x;
}

int pop() {
	int ret = heap[0];
	int x = heap[--size];
	int i = 0;
	while(i*2+1<size) {
		int l = i*2+1, r = i*2+2;
		if( r<size && heap[r]<heap[l]) {
			l = r;
		}
		if( heap[i]<heap[l]) {
			break;
		}
		heap[i]=heap[l];
		i=l;
	}
	heap[i]=x;
	return ret;
}
int main() {
	push(5);
	push(345);
	push(2);
	push(455);
	cout << pop() <<endl;
	cout << pop() <<endl;
	cout << pop() <<endl;
	cout << pop() <<endl;
}
