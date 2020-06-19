#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
const int maxn=1000005;

char s[maxn];
int Next[maxn];
void GetNext()
{
	int len = strlen(s);
	int i = 0, j = -1;
	Next[0] = -1;
	while(i < len)
	{
		if(j == -1 || s[i] == s[j])
		{
			i++;
			j++;
		   	Next[i] = j;
		}
		else j = Next[j];
	}
}
int main()
{
	while(scanf("%s", s) && s[0] != '.')
	{
		GetNext();
		int len = strlen(s);
		if(len % (len - Next[len]) == 0)///如果第i-1位为结尾的循环必定有 i % (i - Next[i]) == 0
		   printf("%d\n", len/(len - Next[len]));///0～i-1共有i个字符，i / (i - Next[i])就是循环次数。
		else
		   printf("1\n");
	}
	return 0;
}

