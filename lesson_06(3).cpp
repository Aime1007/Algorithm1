#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define maxn 1005 
int a[maxn];
int comp(const void*a,const void*b)
{
return *(int*)b-*(int*)a;
}
int main(){
	int T,n,i,t,cnt;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=0 ;i<n ;i++){
			scanf("%d",&a[i]);
		}
		cnt = 0;
		qsort(a,n,sizeof(int),comp);
		do{
			t = a[0];
			a[0] = 0;
			for(i=1 ;i<=t ;i++){
				a[i]--;
				if(a[i]<0){
					cnt = 1;
					break;
				}
			}
			if(cnt==1){
				break;
			}
			qsort(a,n,sizeof(int),comp);
		}while(a[0]>0);
		if(cnt == 1)
			printf("no\n");
		else
			printf("yes\n");
	}
	return 0;
}
