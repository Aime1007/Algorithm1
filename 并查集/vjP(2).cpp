#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e7+5;
int s[maxn],sum[maxn];
void new_set()
{
	for(int i = 0;i < maxn;i++){
		s[i] = i;
		sum[i] = 1;
	}
}
int find_set(int x)
{
	int r = x;
	while(r != s[r]){
		r = s[r];
	}
	while(x != r){
		int j = s[x];
		s[x] = r;
		x = j;
	}
	return r;
}
int union_set(int x,int y)
{
	x = find_set(x);
	y = find_set(y);
	if(x != y){
		if(sum[x] < sum[y]){
			s[x] = y;
			sum[y] += sum[x];
			return sum[y];
		}
		else{
			s[y] = x;
			sum[x] += sum[y];
			return sum[x];
		}
	}
	else{
		return sum[x];
	}
}
int main()
{
	int n,x,y;
	while(~scanf("%d",&n)){
		if(n == 0){
			printf("1\n");
			continue;
		} 
		new_set();
		int ans = 0;
		for(int i = 0;i < n;i++){
			scanf("%d%d",&x,&y);
			ans = max(ans,union_set(x,y));
		}
		printf("%d\n",ans);
	}
	return 0;
}
