#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
const int maxn=1e6+5;
char s[maxn];
char p[maxn];
int Next[maxn];
int n,m;
void getnext(){
    int j=0,k=-1;
    Next[0]=-1;
    while(j<m){
        if(k==-1||p[j]==p[k]){
            j++;
            k++;
            Next[j]=k;
        }
        else
            k=Next[k];
    }
}
int kmp(){
    int i=0,j=0,count=0;
    getnext();
    while(i<n){
        if(j==-1||s[i]==p[j]){
            i++;
            j++;
        }
        else
            j=Next[j];
        if(j==m)
            count++;
            //如果不可以重复j=0 
    }
    return count;
}
int main() {
	int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s%s",p,s);
    	m=strlen(p);
    	n=strlen(s);
        printf("%d\n",kmp());
    }
	return 0;
}

