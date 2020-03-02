#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
#define ms(a,b) memset((a),(b),sizeof((a)))
using namespace std;
typedef long long LL;
const int INF = 2e9;
const LL LNF = 9e18;
const int MOD = 1e9+7;
const int MAXN = 800+10;
 
char maze[MAXN][MAXN];
int n, m, dir[4][2] = {1,0,0,1,-1,0,0,-1};
int ghost[2][2];
 
struct node
{
    int x, y;
};
node M, G;
 
bool caught(node now, int time) //判断会不会被ghost抓住，使用曼哈顿距离判断
{
    if(abs(now.x-ghost[0][0])+abs(now.y-ghost[0][1])<=2*time) return true;
    if(abs(now.x-ghost[1][0])+abs(now.y-ghost[1][1])<=2*time) return true;
    return false;
}
 
queue<node>q[2];
bool vis[2][MAXN][MAXN];
bool bfs(int id, int time)
{
    int Size = q[id].size();    //用于刹车，防止把新入队的点也进行更新
    node now, tmp;
    while(Size--)
    {
        now = q[id].front();
        q[id].pop();
 
        if(caught(now, time)) continue;   //欲出发的点会被ghost抓住， 下一个
        for(int i = 0; i<4; i++)
        {
            tmp.x = now.x + dir[i][0];
            tmp.y = now.y + dir[i][1];
            if(tmp.x>=1 && tmp.x<=n && tmp.y>=1 && tmp.y<=m   //没出界
               && maze[tmp.x][tmp.y]!='X' && maze[tmp.x][tmp.y]!='Z'   //可行通道
               && !vis[id][tmp.x][tmp.y] && !caught(tmp, time))   //没有被访问过，其此时此地不会被抓
            {
                vis[id][tmp.x][tmp.y] = true;
                 //对方已经访问过，则meet。不需判断两者到达的时间是否相等，因为可以走0步，所以就可以一直停留
                if(vis[!id][tmp.x][tmp.y]) return true;
                q[id].push(tmp);
 
            }
        }
    }
    return false;
}
 
int solve()
{
    ms(vis, 0);
    while(!q[0].empty()) q[0].pop();
    while(!q[1].empty()) q[1].pop();
    vis[0][M.x][M.y] = 1;
    vis[1][G.x][G.y] = 1;
    q[0].push(M);
    q[1].push(G);
 
    int time = 0;   //计时器
    while(!q[0].empty() || !q[1].empty())
    {
        time++;
        for(int i = 1; i<=3; i++)   //M在一秒内，可以走0、1、2、3步
            if(bfs(0, time)) return time;
        if(bfs(1, time)) return time;  //G只能走0、1步
    }
    return -1;
}
 
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1; i<=n; i++)
            scanf("%s", maze[i]+1);
 
        int cnt = 0;
        for(int i = 1; i<=n; i++)
        for(int j = 1; j<=m; j++)
        {
           if(maze[i][j]=='Z') ghost[cnt][0] = i, ghost[cnt++][1] = j;
           if(maze[i][j]=='M') M.x = i, M.y = j;
           if(maze[i][j]=='G') G.x = i, G.y = j;
        }
        cout<< solve() <<endl;
    }
}
