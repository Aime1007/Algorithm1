#include<stdio.h>
int count=0,board[100][100];
//覆盖以（tr，tc）为左上角坐标，宽为size的棋盘。残缺块或伪残缺块坐标为（dr，dc） 
void cover(int tr,int tc,int size,int dr,int dc);
int main()
{
    int x,y,k,size=1;
    int i,j;
    scanf("%d%d%d",&k,&x,&y);
    for(i=1;i<=k;i++) size=size*2;//计算2^k 
    cover(0,0,size,x,y);//对原始棋盘进行覆盖 
    for(i=0;i<size;i++)//输出棋盘的覆盖结果 
    {
        for(j=0;j<size;j++)
        {
            printf("%-2d ",board[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void cover(int tr,int tc,int size,int dr,int dc)
{
    if(size==1) return ;
    int t=count++;
    int s=size/2;
    if(dr<tr+s && dc<tc+s) {
    	cover(tr, tc, dr, dc, s);
	}
	else {
		board[tr+s-1][tc+s-1]=t;
		cover(tr, tc, tr+s-1, tc+s-1, s);
	}
	if(dr<tr+s && dc>tc+s) {
		cover(tr, tc+s, dr, dc, s);
	}
	else {
		board[tr+s-1][tc+s]=t;
		cover(tr, tc+s, tr+s-1, tc+s, s);
	}
	if(dr>=tr+s && dc<tr+s) {
		cover(tr+s, tc, dr, dc, s);
	}
	else {
		board[tr+s][tc+s-1]=t;
		cover(tr+s, tc, tr+s, tc+s-1, s);
	}
	if(dr>=tr+s && dc>=tc+s) {
		cover(tr+s, tc+s, dr, dc, s);
	}
	else {
		board[tr=s][tc=s]=t;
		cover(tr+s, tc+s, tr+s, tc+s, s);
	}
}
