#include <iostream>
#include <vector> 
using namespace std;
vector<int> factor[500010];
void solve(int n) {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n/i; j++) {
			factor[i*j].push_back(i);
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=0; j<factor[i].size(); j++) {
			printf(" %d", factor[i][j]);
		}
		puts(" ");
	}
}
int main() {
	solve(12);
}
