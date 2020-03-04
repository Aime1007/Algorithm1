#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n;
char map[12][12][12];
struct Node {
	int x, y, z;
	int step;
}start,endd;
queue<Node> q;
int dx[]={-1,1,0,0,0,0};
int dy[]={0,0,-1,1,0,0};
int dz[]={0,0,0,0,-1,1};
int v[12][12][12];
int bfs() {
	while(!q.empty()) {
		Node now=q.front(); q.pop();
		for(int i=0; i<6; i++) {
			Node next;
			next.x=now.x+dx[i];
			next.y=now.y+dy[i];
			next.z=now.z+dz[i];
			next.step=now.step+1;
			if(next.x<0 || next.x>=n || next.y<0 || next.y>=n
			|| next.z<0 || next.z>=n || v[next.x][next.y][next.z]==1 
			|| map[next.x][next.y][next.z]=='X')
				continue;
			if(next.x==endd.x && next.y==endd.y && next.z==endd.z) {
				return next.step;
			}
			else {
				q.push(next);
				v[next.x][next.y][next.z]=1;
			}
			
		}
	}
	return -1;
}
int main() {
	char s[10];
	while(~scanf("%s %d", s, &n)) {
		memset(v,0,sizeof(v));
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				for(int k=0; k<n; k++) {
					cin>>map[k][j][i];
				}
			}
		}
		
		scanf("%d %d %d", &start.x, &start.y, &start.z);
		scanf("%d %d %d", &endd.x, &endd.y, &endd.z);
		scanf("%s", s);
		start.step=0;
		v[start.x][start.y][start.z]=1;
		q.push(start);
		int ans=bfs();
		if(start.x==endd.x && start.y==endd.y && start.z==endd.z) {
			ans = 0;
		}
		if(ans==-1) cout <<"NO ROUTE"<<endl;
		else cout << n <<" "<< ans <<endl;
	}
}
