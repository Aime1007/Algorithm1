#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
 
struct node
{
    int s[4];
    int step;
};
int s[4],e[4];
int vis[10000];
int bfs()
{
    bool tag=true;
    queue<node>q;
    node cur,next;
    for(int i=0;i<4;i++)cur.s[i]=s[i];
    cur.step=0;
    q.push(cur);
    while(!q.empty()){
        tag=true;
        cur=q.front();q.pop();
        for(int i=0;i<4;i++){
            if(cur.s[i]!=e[i])tag=false;
        }
        if(tag)return cur.step;
 
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++)next.s[j]=cur.s[j];
            next.s[i]=next.s[i]+1;
            if(next.s[i]==10)next.s[i]=1;
            int state=next.s[0]*1000+next.s[1]*100+next.s[2]*10+next.s[3];
            if(!vis[state]){
                vis[state]=true;
                next.step=cur.step+1;
                q.push(next);
            }
        }
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++)next.s[j]=cur.s[j];
            next.s[i]=next.s[i]-1;
            if(next.s[i]==0)next.s[i]=9;
            int state=next.s[0]*1000+next.s[1]*100+next.s[2]*10+next.s[3];
            if(!vis[state]){
                vis[state]=true;
                next.step=cur.step+1;
                q.push(next);
            }
        }
        for(int i=1;i<4;i++){
            for(int j=0;j<4;j++)next.s[j]=cur.s[j];
            int tmp=next.s[i-1];
            next.s[i-1]=next.s[i];
            next.s[i]=tmp;
            int state=next.s[0]*1000+next.s[1]*100+next.s[2]*10+next.s[3];
            if(!vis[state]){
                vis[state]=true;
                next.step=cur.step+1;
                q.push(next);
            }
        }
    }
}
 
int main()
{
    int T;
    scanf("%d",&T);
    char str[8];
    while(T--){
        memset(vis,0,sizeof(vis));
        scanf("%s",str);
        for(int i=0;i<4;i++)s[i]=str[i]-'0';
        scanf("%s",str);
        for(int i=0;i<4;i++)e[i]=str[i]-'0';
        printf("%d\n",bfs());
    }
 
    return 0;
}

