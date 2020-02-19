//���������һ������жϵģ������ǵ���㣬���Ե�һ���������������е��������Ƚ����⣬WA�˺ö�Ρ���

/*
�㷨:����+ ��֦
	minv[i] i��ʱ����С���
	mins[i] i��ʱ����С���
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

void search(int level, int lastR, int lastH, int leftv, int s){ //��ʣlevel��,ǰ������Ϊs


	if( level == 0 ){
		if(0 == leftv && s < ans) ans = s ;
		
		return;
	}
	if (leftv <= 0 ) return ; //level>0 �����Ѿ�û��ʣ�������
	
	if( s + mins[level] >= ans || 2*leftv/lastR + s >= ans) return; 
	//����ʣ�µ����һ������ԭ���õ�����Сֵ�ˣ�����һ����֦����Ҫ������TLE��16ms����
	
	if( leftv < minv[level]) return ; //ʣ�µ����̫С��

	if( level == 1){ //���һ��
		if((lastR-1)*(lastR-1)*(lastH-1) < leftv) return; //ʣ�µ����̫���˲�������

	
		//int r = MIN( sqrt(leftv) , lastR-1);
		for(int r = lastR-1; r > 0; r--) //�Ӵ�Сö�����е�r
			if(0 == leftv % (r*r) && leftv/(r*r) < lastH ) { //���н�
				if( s + 2*leftv/r < ans){
					ans = s + 2*leftv/r ;  
					break; //��һ���ҵ��Ŀ��н�һ������С��
				}
		}	
	}
	else{
		int i,j;
		for(i = lastR-1; i >= level; i--) //�뾶����Ҫ����level
			for(j= lastH - 1 ; j >= level; j--) //�߶����ٴ���level
				search(level-1,i,j,leftv - i*i*j, s+2*i*j); 
	}
}

int main(){
	scanf("%d%d",&n,&m);
	int i,j;
	for( i =MAXR; i>0; i--)
		for(j= MAXH; j>0; j--) if( n - i*i*j >= 0)
			search(m-1 , i,j, n - i*i*j , i*i+2*i*j); //��һ�㣬�����+�����
	
	if(INF == ans) //û�п��н�
		printf("0\n");
	else	printf("%d\n",ans);
	return 0;
}
