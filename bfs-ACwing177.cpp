#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
 
char graph[805][805];   // ��ͼ,���±�1��ʼ��¼
int timee;       // ʱ��
int n,m;        // ��ͼ������
int t;
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};    // ����
struct node {
    // ��
    int x,y;
}gg,mm,zz[2];           // g,m,��ghost
queue<node> q[2],qt;    // gg��mm���У���ʱ����
/**
 *  �ж�ĳ�����Ƿ������������
 **/
bool isOk(node t) {
    if(t.x < 1 || t.x > n || t.y < 1 || t.y > m)
        return false;   // Խ��
    if(graph[t.x][t.y] == 'X' || graph[t.x][t.y] == '\0')
        return false;   // ǽ
    for (int i = 0; i < 2; i++) {
        if(2*timee >= abs(t.x-zz[i].x) + abs(t.y-zz[i].y))
            return false;     // ��������̫��
    }    
    
    return true;
}
 
/**
 * ����������� 
 * mark:�����g����m
 * num: һ������ߵĲ���
 */
bool bfs(int mark,int num,char start,char endd) {
    node a,b;   // ��ʱ�ڵ�
    qt = q[mark];    // ��ʱ����
    for (int i = 0; i < num; i++) {
        // �������п��ܵ���ĵ�
        while(!qt.empty()) {
            a = qt.front(),qt.pop(),q[mark].pop();
            if(!isOk(a)) continue;
            for (int i = 0; i < 4; i++) {
                // 4������
                b = a;
                b.x += dir[i][0],b.y += dir[i][1];
                if(!isOk(b) || graph[b.x][b.y] == start)
                    continue;         // start�����ظ�����ͬ��·
                if(graph[b.x][b.y] == endd)
                    return true;     // ����һ���ܵ�����һ�˿��Ե���ĵ�
                graph[b.x][b.y] = start;    // ����߹��ĵ�
                q[mark].push(b);
            }
        }
        qt = q[mark];
    }
    return false;
}
 
/**
 * ������ 
 */
int solve() {
    // ��ʼ��
    timee = 0;
    while(!q[0].empty()) q[0].pop();
    while(!q[1].empty()) q[1].pop();
    while(!qt.empty()) qt.pop();
    
    q[0].push(mm);
    q[1].push(gg);
    
    while(!q[0].empty() && !q[1].empty()) {
        timee++;
        bool flag1 = bfs(0,3,'M','G');
        bool flag2 = bfs(1,1,'G','M');
        if(flag1 || flag2)
            return timee;
    }
    return -1;
}
 
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&m);
        memset(graph,'X',sizeof(graph));
        for(int k = 0,i = 1;i <= n;i++) {
            scanf("%s",graph[i]+1);
            for(int j = 1;j <= m;j++) {
                if(graph[i][j] == 'M') mm.x = i,mm.y = j;
                if(graph[i][j] == 'G') gg.x = i,gg.y = j;
                if(graph[i][j] == 'Z') zz[k].x = i,zz[k].y = j,k++;
                
            }
        }
        printf("%d\n",solve());
    }
    return 0;
}

