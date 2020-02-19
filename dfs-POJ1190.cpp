//我是在最后一层进行判断的，而不是第零层，所以第一次搜索（主函数中的搜索）比较特殊，WA了好多次……

/*
算法:搜索+ 剪枝
	minv[i] i层时的最小体积
	mins[i] i层时的最小体积
*/
#include <stdio.h>
#include <math.h>
#define MIN(x,y) ((x)<(y)?(x):(y))
#define INF 1000000
#define MAXR 25
#define MAXH 25

int minv[MAXH];
int mins[MAXR];
int n,m;
int ans = INF;

void build(){
	int i=1;
	minv[1] = 1;
	mins[1] = 2;
	for(i=2; i<MAXH; i++)
		minv[i] = minv[i-1] + i*i*i,
		mins[i] = mins[i-1] + 2*i*i;
};

void search(int level, int lastR, int lastH, int leftv, int s){ //还剩level层,前面的面积为s


	if( level == 0 ){
		if(0 == leftv && s < ans) ans = s ;
		
		return;
	}
	if (leftv <= 0 ) return ; //level>0 但是已经没有剩余体积了
	
	if( s + mins[level] >= ans || 2*leftv/lastR + s >= ans) return; 
	//！！剩下的面积一定大于原来得到的最小值了！！这一步剪枝最重要！！从TLE到16ms……
	
	if( leftv < minv[level]) return ; //剩下的体积太小了

	if( level == 1){ //最后一层
		if((lastR-1)*(lastR-1)*(lastH-1) < leftv) return; //剩下的体积太多了不可能了

	
		//int r = MIN( sqrt(leftv) , lastR-1);
		for(int r = lastR-1; r > 0; r--) //从大到小枚举所有的r
			if(0 == leftv % (r*r) && leftv/(r*r) < lastH ) { //可行解
				if( s + 2*leftv/r < ans){
					ans = s + 2*leftv/r ;  
					break; //第一个找到的可行解一定是最小的
				}
		}	
	}
	else{
		int i,j;
		for(i = lastR-1; i >= level; i--) //半径至少要大于level
			for(j= lastH - 1 ; j >= level; j--) //高度至少大于level
				search(level-1,i,j,leftv - i*i*j, s+2*i*j); 
	}
}

int main(){
	scanf("%d%d",&n,&m);
	int i,j;
	for( i =MAXR; i>0; i--)
		for(j= MAXH; j>0; j--) if( n - i*i*j >= 0)
			search(m-1 , i,j, n - i*i*j , i*i+2*i*j); //第一层，底面积+侧面积
	
	if(INF == ans) //没有可行解
		printf("0\n");
	else	printf("%d\n",ans);
	return 0;
}
