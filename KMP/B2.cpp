#include<cstdio>
#include<cstring>
const int maxn=1e6+5;
int s[maxn];
int p[maxn];
int Next[maxn];
int m,n;
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
    int i=0,j=0;
    getnext();
    while(i<n){
        if(j==-1||s[i]==p[j]){
            i++;
            j++;
        }
        else
            j=Next[j];
        if(j==m)
            return i;
    }
    return -1;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d",&s[i]);
        for(int i=0;i<m;i++)
            scanf("%d",&p[i]);
        if(kmp()==-1)
            printf("-1\n");
        else
            printf("%d\n",kmp()-m+1);
    }
    return 0;
}
