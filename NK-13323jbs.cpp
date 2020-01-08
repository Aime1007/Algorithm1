#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN=1050000;
int n;
int a[MAXN];

int dfs(int i,int l) {
    if( l==log(n)/log(2) || i==n) return l;
    
    if( a[i]<=a[0] ) return dfs(i+1,l+1);
    
    return dfs(i+1,l);
}
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    
    int ans;
    ans=dfs(1,0);
    
    if(ans == log(n)/log(2))
        printf("%d", ans);
    else 
        printf("%d", ans+1);
}

