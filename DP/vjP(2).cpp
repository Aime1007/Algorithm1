#include<iostream>
#include<cstring>
using namespace std;
#define N 20 + 5
int dp[N][N]; 
int a[N];
int main() {
    int n;
    while(cin >> n) {
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++) cin >> a[i]; 
        for(int i = 0; i <= n; i++) dp[0][i] = 1;
        for(int i = 0; i <= 40; i++) {
            for(int j = 1; j <= n; j++) {
                dp[i][j] = dp[i][j-1];
                if(i >= a[j])  
                    dp[i][j] += dp[i - a[j]][j-1];
            }
        }
        cout << dp[40][n] << endl;
    }
    return 0;
}
