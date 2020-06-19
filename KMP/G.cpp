#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
const int maxn=1000005;
char p[maxn];
int Next[maxn];
int len;
void getnext(){
    int j=0,k=-1;
    Next[0]=-1;
    while(j<len){
        if(k==-1||p[j]==p[k]){
            j++;
            k++;
            Next[j]=k;
        }
        else
            k=Next[k];
    }
}
int main() {
	while(~scanf("%s", p)) {
		if(p[0]=='.') break;
		getnext();
		len=strlen(p);
		if(len%(len-Next[len])==0)
			printf("%d\n", len/(len - Next[len]));
		else
			printf("1\n");
	}	 
	
	return 0;
}

