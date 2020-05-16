#include<stdio.h>
#include<string.h>
int fx[]={-1,0,1, 0};
int fy[]={ 0,1,0,-1};

int sx,sy,ex,ey;
int i,j,k,l,g;
int n,m;
int MAP[1001][1001],hash[1001][1001],d[1001][1001];
struct node
{
    int x;
    int y;
    int turn;
}que[1000000];
int bfs()
{
    struct node now;
    int tail=1;
    now.turn=0,i=0,que[0].x=sx,que[0].y=sy,que[0].turn=0,hash[sx][sy]=1;
    memset(d,-1,sizeof(d));
    while(i!=tail)
    {
        if(que[i].turn>=3) return 0;
        for(k=0;k<4;k++)
        {
            now.x=que[i].x+fx[k],now.y=que[i].y+fy[k];
            while(now.x>=1 && now.x<=m && now.y>=1 && now.y<=n && MAP[now.x][now.y]==0 )
            {
                //if(d[now.x][now.y]==d[que[i].x][que[i].y] && d[now.x][now.y]!=-1 && d[que[i].x][que[i].y]!=-1) break;//这句包括开头定义的数组d 本意想用作剪枝，但是加上后自己的数据也没过，但是可以ac，这题的数据太水了。
                if(hash[now.x][now.y]==0)
                {
                    now.turn=que[i].turn+1;
                    d[now.x][now.y]=k;
                    que[tail++]=now;
                    hash[now.x][now.y]=1;
                    if(now.x==ex && now.y==ey)
                        if(now.turn<=3) return 1;
                        else return 0;
                }
                now.x+=fx[k],now.y+=fy[k];
            }
        }
        i++;
    }
    return 0;
}

int main()
{
    while(~scanf("%d%d",&m,&n),m)
    {
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
                scanf("%d",&MAP[i][j]);
        scanf("%d",&l);
        while(l--)
        {
            scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
            if((MAP[sx][sy]!=MAP[ex][ey]) || MAP[sx][sy]==0
               || MAP[ex][ey]==0 || (sx==ex && sy==ey)
               || sx>m ||ex>m ||sy>n ||ey>n)
            {
                puts("NO");
                continue;
            }
            memset(hash,0,sizeof(hash));
            g=MAP[ex][ey];
            MAP[ex][ey]=0;
            if(bfs()) printf("YES\n");
            else printf("NO\n");
            MAP[ex][ey]=g;
        }
    }
    return 0;
}

