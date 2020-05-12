#include<iostream>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;
struct Node {
    int x,y;
    int step;
};
char map[205][205];
int visited[205][205];
int start_x,start_y,step;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
queue<Node>q;
int m,n;
int BFS()
{
    while(!q.empty()){
        Node z=q.front();
        for(int i=0; i<4; i++)
        {
            int x=z.x+dx[i];
            int y=z.y+dy[i];
            int step=z.step+1;
            if(x<0||x>=n||y<0||y>=m||map[x][y]=='#'||visited[x][y]==1){
                continue;
            }
            Node ptr;
            ptr.x = x; ptr.y = y; ptr.step = step;
            if(map[ptr.x][ptr.y]=='x'){
                ptr.step += 1;
            }
            if(map[ptr.x][ptr.y]=='r'){
                return ptr.step;
            }
            q.push(ptr);
            visited[ptr.x][ptr.y] = 1;
        }
        q.pop();
    }
    return -1;
}

int main()
{
    while(cin>>n>>m){
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin >> map[i][j];
                visited[i][j] = 0;
                if(map[i][j] == 'a'){
                    start_x=i;start_y=j;
                }
            }
        }
        while(!q.empty()) {
            q.pop();
        }
        Node p;
        p.x=start_x;
        p.y=start_y;
        p.step=0;
        visited[p.x][p.y]=1;
        q.push(p);
        int c=BFS();
        if (c==-1){
            cout <<"Poor ANGEL has to stay in the prison all his life."<<endl;
        }
        else {
            cout << c <<endl;
        }
    }
}
