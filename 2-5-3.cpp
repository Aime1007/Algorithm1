#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=100;
vector<int> G[MAXN];
int color[MAXN];

bool dfs(int v, int c) {
	color[v] = c;
	for(int i=0; i<G[v].size(); i++) {
		if(color[G[v][i]]==c) return false;
		
		if(color[G[v][i]]==0 && !dfs(G[v][i], -c)) return false;
	}
	return true;
}
int main() {
	int V,E;
	scanf("%d %d", &V, &E);
	for(int i=0; i<E; i++) {
		int s, t;
		scanf("%d %d", &s, &t);
		G[s].push_back(t);
		G[t].push_back(s);
	}
	
	for(int i=0; i<V; i++) {
		if(color[i]==0) {
			if(!dfs(i,1)) {
				printf("NO");
				return 0;
			}
		}
	}
	printf("YES");
}
