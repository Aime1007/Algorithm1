#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const  int maxn=1e4+100;
int n;
struct node{
    int pro,d;
}s[maxn];
bool cmp(node x,node y){
    return x.pro>y.pro;
}
int f[maxn];
int findd(int x){
    if(f[x]==-1)  return x;
    return f[x]=findd(f[x]);
}
int main(){
    while(~scanf("%d",&n)){
        memset(f,-1,sizeof(f));
        for (int i = 1; i <= n; ++i) {
            scanf(" %d %d",&s[i].pro,&s[i].d);
        }
        sort(s+1,s+n+1,cmp);
        int ans=0;
        for(int i=1; i<=n; i++){
            int v=findd(s[i].d);
            if(v>0){
                ans+=s[i].pro;
                f[v]=v-1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
