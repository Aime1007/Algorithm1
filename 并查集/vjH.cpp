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
int fa[maxn];
int get(int x){
    if(fa[x]==-1)  return x;
    return fa[x]=get(fa[x]);
}
int main(){
    while(~scanf("%d",&n)){
        memset(fa,-1,sizeof(fa));
        for (int i = 1; i <= n; i++) {
            scanf(" %d %d",&s[i].pro,&s[i].d);
        }
        sort(s+1,s+n+1,cmp);
        int ans=0;
        for(int i=1; i<=n; i++){
            int v=get(s[i].d);
            if(v>0){
                ans+=s[i].pro;
                fa[v]=v-1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
