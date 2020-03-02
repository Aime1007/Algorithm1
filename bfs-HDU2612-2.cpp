#include <stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
char map[205][205];
int visited[205][205];
int n,m;
int start_x1,start_y1,start_x2,start_y2;
struct Node {
    int x,y;
    int time;
};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
queue<Node>q;
int kfc[205][205];


void BFS()
{
    while(!q.empty()){
        Node p;
        p=q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int pathx=p.x+dx[i];
            int pathy=p.y+dy[i];
            int time = p.time + 11;
            if(pathx<0||pathx>=n||pathy<0||pathy>=m||map[pathx][pathy]=='#'||visited[pathx][pathy]==1) {
                continue ;
            }
            Node next;
            next.x=pathx;
            next.y=pathy;
            next.time=time;
            if(map[pathx][pathy]=='@'){
                kfc[pathx][pathy] = kfc[pathx][pathy] + time;
                //cout << kfc[pathx][pathy] <<endl;
            }
            q.push(next);
            visited[pathx][pathy]=1;
        }
    }
}
int main()
{
    while(cin>>n>>m){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>map[i][j];
                visited[i][j]=0;
                kfc[i][j]=0;
                if(map[i][j]=='Y'){
                    start_x1=i;start_y1=j;
                }
                if(map[i][j]=='M'){
                    start_x2=i;start_y2=j;
                }
            }
        }
        while(!q.empty()){
            q.pop();
        }
        Node p1;
        p1.x=start_x1;p1.y=start_y1;p1.time=0;
        q.push(p1);
        visited[p1.x][p1.y]=1;
        BFS();
        
        while(!q.empty()){
            q.pop();
        }
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                visited[i][j]=0;
                
        Node p2;
        p2.x=start_x2;p2.y=start_y2;p2.time=0;
        q.push(p2);
        visited[p1.x][p1.y]=1;
        BFS();
        
        int min=10000;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(kfc[i][j]!=0&&kfc[i][j]<min)
                {
                    min=kfc[i][j];
                }
            }
        }
        cout << min <<endl;
    }
    return 0;
}
