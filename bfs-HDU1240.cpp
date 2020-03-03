#include <iostream>
#include <queue>
using namespace std;
int n, cnt=0;
char map[12][12][12];
struct Node {
	int x, y, z;
	int step;
}start,end;
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
			if(next.x<1 || next.x>n || next.y<1 || next.y>n
			|| next.z<1 || next.z>n || v[next.x][next.y][next.z]==1)
				continue;
			if(next.x==end.x && next.y==end.y && next.z==end.z) {
				return next.step;
			}
			else
			q.push(next);
		}
	}
	return -1;
}
int main() {
	while(~scanf("START %d", &n)) {
		cnt++;
		for(int k=1; k<=n; k++) {
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=n; j++) {
					scanf("%c", &map[k][i][j]);	
				}
				getchar();
			}
		}
		for(int k=1; k<=n; k++) {
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=n; j++) {
					printf("%c", map[k][i][j]);	
				}
				
			}
		}
//		scanf("%d %d %d", &start.x, &start.y, &start.z);
//		scanf("%d %d %d", &end.x, &end.y, &end.z);
//		start.step=0;
//		q.push(start);
//		int ans=bfs();
//		if(ans==-1) cout <<"NO ROUTE"<<endl;
//		else cout << cnt <<" "<< ans <<endl;
//		scanf("END");
	}
}
