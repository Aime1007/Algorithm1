#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
struct node {
	char x,y,z;
}a,b,c;
int main() {
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a.x>>a.y>>a.z;
		cin>>b.x>>b.y>>b.z;
		cin>>c.x>>c.y>>c.z;
		cout <<"Gas Station #"<<i<<":"<<endl;
		cout <<"   Input:  "<<a.x<<a.y<<a.z<<" "<<b.x<<b.y<<b.z<<" "<<c.x<<c.y<<c.z<<endl;
		if(a.x=='-') a.x='2';
		if(a.y=='-') a.y='0';
		if(a.z=='-') a.z='0';
		
		if(b.x=='-') {
			if(b.y>a.y) b.x=a.x;
			else if(b.y<a.y) b.x=a.x+1;
			else {
				if(b.z<a.z) b.x=a.x+1;
				else if(b.z>a.z) b.x=a.x;
				else b.x=a.x+1;
			}
		}
		else if(b.y=='-') {
			if(b.x==a.x) {
				if(b.z<=a.z) b.y=a.y+1;
				else b.y=a.y;
			}
			else b.y='0';
		}
		else if(b.z=='-') {
			if(a.x==b.x) {
				if(a.y==b.y) b.z=a.z+1;
				else b.z='0';
			}
			else b.z='0';
		}
		
		if(c.x=='-') {
			if(c.y>b.y) c.x=b.x;
			else if(c.y<b.y) c.x=b.x+1;
			else {
				if(c.z<b.z) c.x=b.x+1;
				else if(c.z>b.z) c.x=b.x;
				else c.x=b.x+1;
			}
		}
		else if(c.y=='-') {
			if(c.x==b.x) {
				if(c.z<=b.z) c.y=b.y+1;
				else c.y=b.y;
			}
			else c.y='0';
		}
		else if(c.z=='-') {
			if(b.x==c.x) {
				if(b.y==c.y) c.z=b.z+1;
				else c.z='0';
			}
			else c.z='0';
		}
		cout <<"   Output: "<<a.x<<a.y<<a.z<<" "<<b.x<<b.y<<b.z<<" "<<
		c.x<<c.y<<c.z<<endl;
		cout <<endl;
	}
}
