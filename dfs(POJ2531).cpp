#include <iostream>
using namespace std;
const int maxn = 22;
int n;
int G[maxn][maxn];
bool book[maxn];
int ans;
void dfs(int k, int sum) {
	int num = sum;
	for(int i=1; i<=n; i++) {
		if(book[i]) {
			num -= G[k][i];
		}
		else {
			num += G[k][i];
		}
	}
	if( num>ans)
		ans=num;
	for(int i=k+1; i<=n; i++) {
//		if( num>sum) {//Ð¡¼ôÖ¦ 
			book[i]=true;
			dfs(i, num);
			book[i]=false;
//		}
	}
}

int main() {
	cin >> n;
	for(int i=1; i<=n ;i++) {
		for(int j=1; j<=n; j++) {
			cin >> G[i][j];
		}
	}
	
	book[1]=true;
	dfs (1, 0);
	cout << ans <<endl;
} 
