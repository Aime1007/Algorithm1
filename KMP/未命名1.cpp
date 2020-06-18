#include <iostream>
#include <string>
#include <vector>
using namespace std;

//部分匹配表
void cal_next(string &str, vector<int> &next)
{
	const int len = str.size();
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j < len - 1)
	{
		if (k == -1 || str[j] == str[k])
		{
			++k;
			++j;
			next[j] = k;//表示第j个字符有k个匹配（“最大长度值” 整体向右移动一位，然后初始值赋为-1）
		}
		else
			k = next[k];//往前回溯
	}
}

vector<int> KMP(string &str1, string &str2, vector<int> &next)
{
	vector<int> vec;
	cal_next(str2, next);
	int i = 0;//i是str1的下标
	int j = 0;//j是str2的下标
	int str1_size = str1.size();
	int str2_size = str2.size();
	while (i < str1_size && j < str2_size)
	{
		//如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），
		//都令i++，j++. 注意：这里判断顺序不能调换！
		if (j == -1 || str1[i] == str2[j])
		{
			++i;
			++j;
		}
		else
			j = next[j];//当前字符匹配失败，直接从str[j]开始比较，i的位置不变
		if (j == str2_size)//匹配成功
		{
			vec.push_back(i - j);//记录下完全匹配最开始的位置
			j = -1;//重置
		}
	}
	return vec;
}

int main(int argc, char const *argv[])
{
	vector<int> vec(20, 0);
	vector<int> vec_test;
	string str1 = "bacbababadababacambabacaddababacasdsd";
	string str2 = "ababaca";
	vec_test = KMP(str1, str2, vec);
	for (const auto v : vec_test)
		cout << v << endl;
	return 0;
}
