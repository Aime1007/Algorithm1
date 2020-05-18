#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int M = 111;

int n, m;
int max_turn;
int star_x, star_y, end_x, end_y;
char g[M][M];
bool vis[M][M];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
//?,?,?,?


struct Node
{
    int x, y;
    int turn_num;

};

int Bfs()
{
    queue <Node> q;
    Node q1;
    q1.x = star_x;
    q1.y = star_y;
    q1.turn_num = -1;
    q.push(q1);
    vis[star_x][star_y] = 1;

    while (!q.empty())
    {
        Node q2 = q.front();
        q.pop();

        if (q2.x == end_x && q2.y == end_y && q2.turn_num <= max_turn)
        {
            return 1;
        }

        q1.turn_num = q2.turn_num + 1;
        
        for (int i = 0; i < 4; i++)
        {
            q1.x = q2.x + dir[i][0];
            q1.y = q2.y + dir[i][1];
            while (q1.x >= 1 && q1.x <= n && q1.y >= 1 && q1.y <= m && g[q1.x][q1.y] == '.'/* && !vis[q1.x][q1.y]*/)//**********
            {
                if (!vis[q1.x][q1.y])//*********************************
                {
                q.push(q1);
                vis[q1.x][q1.y] = 1;
                }
                q1.x += dir[i][0];
                q1.y += dir[i][1];
            }
        }
    
    }
    return 0;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf(" %c", &g[i][j]);
            }
        }

        scanf("%d%d%d%d%d", &max_turn, &star_y, &star_x, &end_y, &end_x);

        memset(vis, 0, sizeof(vis));



        if (Bfs())
        {
            puts("yes");
        }
        else
        {
            puts("no");
        }
    }
    return 0;
}
