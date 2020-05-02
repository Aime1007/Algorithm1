#include<cstdio>
#include<cstring>
#include<algorithm>
#define max 10002
using namespace std;
int father[max],ran[max],num[max];
int a,b;

void init()
{
    int i;
    for(i=1;i<=a;i++)
    {
        father[i]=i;//????? 
        ran[i]=1;//???????????? 
        num[i]=0;//??????? 
    }
}

int find(int x)
{
    if(x==father[x]) return x;
    int t=father[x];
    father[x]=find(father[x]);//???? ,?????? 
    num[x]+=num[t];//???????????????????????????
    return father[x];
}

void join(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy)
    {
        father[fx]=fy;//?????????????? 
        ran[fy]+=ran[fx];//fy?????????????????????? 
        num[fx]=1;//???????????? 
    }
}

int main()
{
    int i,N,m,n,cot=1;
    char c;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d%d",&a,&b);
        getchar();
        init();
        printf("Case %d:\n",cot++);
        for(i=0;i<b;i++)
        {
            scanf("%c",&c);
            if(c=='T')
            {
                scanf("%d%d",&m,&n);
                getchar();
                join(m,n);
            }
            else
            {
                scanf("%d",&m);
                getchar();
                int t=find(m);//????????????
                printf("%d %d %d\n",t,ran[t],num[m]);
            }
        }
    }
    return 0;
} 
