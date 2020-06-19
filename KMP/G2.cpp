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
		if(len % (len - Next[len]) == 0)///�����i-1λΪ��β��ѭ���ض��� i % (i - Next[i]) == 0
		   printf("%d\n", len/(len - Next[len]));///0��i-1����i���ַ���i / (i - Next[i])����ѭ��������
		else
		   printf("1\n");
	}
	return 0;
}

