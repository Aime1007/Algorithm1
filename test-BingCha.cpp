#include <iostream>
using namespace std;
int n, m;
int parent[100000];
int visited[100000];
void init() {
	for(int i=0; i<=99999; i++) {
		parent[i]=i;
	}
}
int find(int a) {
	int root=a;
	while(root!=parent[root]) {
		root=parent[root];
	}
	while(a!=root) {
		int t=parent[a];
		parent[a]=root;
		a=t;
	}
	return root;
}
void merge(int a,int b) {
	a=find(a);
	b=find(b);
	if(a != b) parent[a]=parent[b];
}
int main(){
	int n;
	cin >>n;
	init();
	while(n--){
		int k;cin >> k;
		int kk=k;
		int index,index2;
		cin >>index;
		k--;
		while(k--){
			scanf("%d",&index2);
			merge(index,index2);
		}
		if(kk>1){
			visited[index2]=1;
		}
	}
	int m;
	scanf("%d",&m);
	int flag=0;
	while(m--){
		int index;
		scanf("%d",&index);
		if(find(index)==index&&visited[index]==0){
			if(flag==0){
				printf("%05d",index);
				flag=1;
			}
			else{
				printf(" %05d",index);
			}
			visited[index]=1;
		}
	}
	if(flag==0){
		printf("No one is handsome");
	}
	return 0;
}
