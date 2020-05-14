
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 1005;
struct info{
    int x,y;
    int s;
    bool operator<(const info a)const{
        return a.s < s;
    }
};
priority_queue<info>q;
char map[maxn][maxn];
bool visited[maxn][maxn];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
int n,m;
void clear_set()
{
    memset(visited,false,sizeof(visited));
    while(!q.empty()){
        q.pop();
    }
}
void bfs(int x,int y)
{
    info p,ptr;
    while(!q.empty()){
        ptr = q.top();
        q.pop();
        if(ptr.x == x && ptr.y == y){
            printf("%d\n",ptr.s);
            break;
        }
        for(int i = 0;i < 4;i++){
            p.x = ptr.x + dx[i];
            p.y = ptr.y + dy[i];
            p.s = ptr.s;
            if(p.x < 0 || p.x >= m || p.y < 0 || p.y >= n || visited[p.x][p.y]){
                continue;
            }
            visited[p.x][p.y] = true;
            if(map[p.x][p.y] == '.'){
                p.s += 1;
            }
            q.push(p);
        }
    }
}
int main()
{    
    while(~scanf("%d%d",&m,&n) && m && n){
        clear_set();
        for(int i = 0;i < m;i++){
            scanf("%s",map[i]);
        }
        info p;
        int x,y;
        scanf("%d%d",&x,&y);
        p.x = x - 1;p.y = y-1;
        p.s = 0;visited[p.x][p.y] = true;
        q.push(p);
        scanf("%d%d",&x,&y);
        bfs(x-1,y-1);
    }
    return 0;
}

