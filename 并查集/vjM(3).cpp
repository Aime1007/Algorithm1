//It is made by HolseLee on 29th May 2018
//POJ 2912
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<iomanip>
#include<algorithm>
#define Fi(i,a,b) for(int i=a;i<=b;i++)
#define Fx(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=507;const int M=2007;
int n,m,rank[N],fa[N];
inline int find(int a)
{
    if(fa[a]!=a){
        int father=find(fa[a]);
        rank[a]=(rank[a]+rank[fa[a]])%3;
        fa[a]=father;}
    return fa[a];
}
inline bool check(int a,int b,int c)
{
    int fx=find(a);int fy=find(b);
    if(fx==fy){if((rank[b]-rank[a]+3)%3!=c)return true;}
    else{fa[fy]=fx;rank[fy]=(rank[a]-rank[b]+c+3)%3;}return false;
}
int main()
{
    for(;scanf("%d%d",&n,&m)!=EOF;){
        int x[M],y[M],ch[M];
        int tot=0,cnt=0,ans=0,c;bool flag;
        Fi(i,1,m){scanf("%d%c%d",&x[i],&ch[i],&y[i]);}
        Fi(i,0,n-1){flag=true;Fi(j,0,n-1)fa[j]=j,rank[j]=0;
        Fi(j,1,m){if(x[j]==i||y[j]==i)continue;
        if(ch[j]=='=')c=0;else if(ch[j]=='>')c=1;else c=2;
        if(check(x[j],y[j],c)){cnt=max(cnt,j);flag=false;break;}}
        if(flag){tot++;ans=i;}} 
        if(!tot)printf("Impossible\n");
        else if(tot>1)printf("Can not determine\n");
        else printf("Player %d can be determined to be the judge after %d lines\n",ans,cnt);
    }return 0;
}
