#include<stdio.h>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 35;
int main()
{
    int i,j,num;
    char str,b;
    double w,A,B,C,data;
    double dp[maxn],m[maxn];
    int n;
    while(cin>>w>>n && n)
    {
        memset(dp,0,sizeof(dp));
        int cnt = 1;
        for(i=0; i<n; i++)
        {
            A = 0,B = 0,C = 0;
            cin >> num;
            int flag = 0;
            for(j=0; j<num; j++)
            {
                cin>>str>>b>>data;
                if(str == 'A')
                    A+=data;
                else if(str == 'B')
                    B+=data;
                else if(str == 'C')
                    C+=data;
                else
                    flag =1;
            }
            if(!flag && A<=600 && B<=600 && C<=600 && A+B+C <=1000 )
             {
                  m[cnt++] = A+B+C;
             }
        }
 
        for(i=1; i<cnt; i++)
        {
            for(j=i-1; j>=0; j--)
             {
                 if(dp[j] + m[i] <= w)
                    dp[i] = max(dp[i], dp[j]+m[i]);
             }
        }
        double Max = 0;
        for(i=1; i<cnt; i++)
        {
            if(dp[i] > Max)
                Max = dp[i];
        }
        printf("%.2lf\n",Max);
    }
 
    return 0;
}
