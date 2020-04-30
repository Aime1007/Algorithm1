#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[100001][14];
int main()
{
	int n,i,j,x,y;
	while(scanf("%d",&n)&&n)
	{
		int maxx=0;
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&x,&y);
			dp[y][x+1]++;
			if(maxx<y)
			maxx=y;
		}
		for(i=maxx-1;i>=0;i--)
		{
			for(j=1;j<=11;j++)
			{
				dp[i][j]+=max( max( dp[i+1][j],dp[i+1][j+1] ) ,dp[i+1][j-1]);		
			}
		}
		printf("%d\n",dp[0][6]);
	}
}
