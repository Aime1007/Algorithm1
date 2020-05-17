#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
int n,m;//????,???? 
int map[1001][1001];//??
int mino[1001][1001];
int x1,y1,x2,y2;

struct spot{
    int x;
    int y;
    //x,y??? 
    int dir;//?????
    //? 1
    //? 2
    //? 3 
    //? 4 
    //???(???)0
    int turns;//???? 
};

spot s,e;//???????

bool bfs(){
    spot f;
    spot t;
    queue<spot>llk;
    
    llk.push(s);
    
    while (llk.size()){
        f=llk.front();
        llk.pop();
        for (int i=1;i<=4;i++){
            t.x=f.x;
            t.y=f.y;
            t.dir=i;//??
            t.turns=f.turns;
            switch (i){
                case 1:
                    t.x++;
                    break;
                case 2:
                    t.y--;
                    break;
                case 3:
                    t.x--;
                    break;
                case 4:
                    t.y++;
                    break;
            }
            //????? 
            if (!(t.x>=0&&t.x<n&&t.y>=0&&t.y<m)){//???? 
                continue;
            }
            bool end=(t.x==e.x&&t.y==e.y);
            if (map[t.x][t.y]!=0&&!end){//???? 
                continue;
            }
            
            if(t.dir!=f.dir&&f.dir!=0){//????????
                t.turns++;
            }
            if (t.turns==3){//?????,??????
                continue;
            }

            if (end){
                return true;
            }
            if (t.turns<=mino[t.x][t.y]){
                mino[t.x][t.y]=t.turns;
                llk.push(t);//????
            }
        }
    }
    return false;
}
int main(){
    //freopen("G://Test.txt","r",stdin);  
    while (scanf("%d%d",&n,&m)&&(n+m)){//??n,m>=0 ??n,m???0?(n+m)??0 
        memset(map,0,sizeof(map));//????0 
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                scanf("%d",&map[i][j]);
            }
        }
        int q;
        scanf("%d",&q);
        while(q--){
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            //?????
            x1--;y1--;x2--;y2--;
            if (map[x1][y1]!=map[x2][y2]||
                    map[x1][y1]==0||map[x2][y2]==0||
                        (x1==x2&&y1==y2)){
                cout<<"NO"<<endl;
            }
            //????????????
            else {
                memset(mino,3,sizeof(mino));
                //???
                s.x=x1;
                s.y=y1;
                s.dir=0;//??? 
                s.turns=0;
                mino[s.x][s.y]=0;
                e.x=x2;
                e.y=y2;
                if (bfs()){
                    cout<<"YES"<<endl;
                }
                else {
                    cout<<"NO"<<endl;
                }
            }
        }
    }
}
