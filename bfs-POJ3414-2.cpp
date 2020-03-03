#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <cmath>
using namespace std;
struct Data{
	int x,y;
	string s;
	bool operator <(Data b) const{
		if(x!=b.x) return x<b.x;
		return y<b.y;
	}
};


int main(){
	int A,B,C,sum;
	Data t,temp;
	cin>>A>>B>>C;
	t.x=t.y=0; temp.x=-1;
	queue<Data> Q;
	map<Data,Data> M;
	while(!Q.empty()) Q.pop();
	Q.push(t); M[t]=temp;
	while(!Q.empty()){
		t=Q.front(); Q.pop();
		if(t.x==C||t.y==C) break;
		temp.x=A; temp.y=t.y; temp.s="FILL(1)";
		if(M.find(temp)==M.end()) Q.push(temp),M[temp]=t;
		
		temp.x=t.x; temp.y=B; temp.s="FILL(2)";
		if(M.find(temp)==M.end()) Q.push(temp),M[temp]=t;
		
		temp.x=0; temp.y=t.y; temp.s="DROP(1)";
		if(M.find(temp)==M.end()) Q.push(temp),M[temp]=t;
		
		temp.x=t.x; temp.y=0; temp.s="DROP(2)";
		if(M.find(temp)==M.end()) Q.push(temp),M[temp]=t;
		
		temp.x=min(t.x+t.y,A);
		temp.y=max(0,t.y-A+t.x); temp.s="POUR(2,1)";
		if(M.find(temp)==M.end()) Q.push(temp),M[temp]=t;
		
		temp.x=max(0,t.x-B+t.y);
		temp.y=min(t.x+t.y,B); temp.s="POUR(1,2)";
		if(M.find(temp)==M.end()) Q.push(temp),M[temp]=t;
	}
	if(t.x==C||t.y==C){
		string ans=""; sum=0;
		for(temp=t;temp.x||temp.y;temp=M[temp]) ans=temp.s+"\n"+ans,sum++;
		cout<<sum<<endl<<ans;
	}
	else cout<<"impossible"<<endl;
	return 0;
}
