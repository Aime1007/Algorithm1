#include <iostream>
#include <cstdio>
using namespace std;
int g,p;
int w,t,l;
//struct node {
//	int x,y,z;
//}cnt[20];
//int index;
void dfs(int now,int score,int tag) {
	if(now==g && score==p) {
//		int flag=0;
//		for(int i=0; i<index; i++) {
//			if(w==cnt[i].x && t==cnt[i].y && l==cnt[i].z) {
//				flag=1;
//				break;
//			}
//		}
//		if(flag==0) {
			printf("%d-%d-%d\n", w, t, l);
			cnt[index].x=w; cnt[index].y=t; cnt[index].z=l;
//			index++;
//		}
		
	}
	if(now==g || score>=p) {
		return;
	}
	for(int i=0; i<3; i++) {
		if(i==0 && tag==1) {
			w++;
			dfs(now+1,score+3,1);
			w--;
			tag=2;
		}
		else if(i==1 && tag==2) {
			t++;
			dfs(now+1,score+1,2);
			tag=3;
		}
		else if(i==2 && tag==3){
			l++;
			dfs(now+1,score,3);
			l--;
		}
	}
	return;
}
int main() {
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d%d", &g, &p);
		printf("Team #%d\n",i);
		printf("Games: %d\n",g);
		printf("Points: %d\n",p);
		printf("Possible records:\n");
		dfs(0,0,1);
		printf("\n");
	}
	return 0;
} 
