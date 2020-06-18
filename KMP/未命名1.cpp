#include <iostream>
#include <string>
#include <vector>
using namespace std;

//����ƥ���
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
			next[j] = k;//��ʾ��j���ַ���k��ƥ�䣨����󳤶�ֵ�� ���������ƶ�һλ��Ȼ���ʼֵ��Ϊ-1��
		}
		else
			k = next[k];//��ǰ����
	}
}

vector<int> KMP(string &str1, string &str2, vector<int> &next)
{
	vector<int> vec;
	cal_next(str2, next);
	int i = 0;//i��str1���±�
	int j = 0;//j��str2���±�
	int str1_size = str1.size();
	int str2_size = str2.size();
	while (i < str1_size && j < str2_size)
	{
		//���j = -1�����ߵ�ǰ�ַ�ƥ��ɹ�����S[i] == P[j]����
		//����i++��j++. ע�⣺�����ж�˳���ܵ�����
		if (j == -1 || str1[i] == str2[j])
		{
			++i;
			++j;
		}
		else
			j = next[j];//��ǰ�ַ�ƥ��ʧ�ܣ�ֱ�Ӵ�str[j]��ʼ�Ƚϣ�i��λ�ò���
		if (j == str2_size)//ƥ��ɹ�
		{
			vec.push_back(i - j);//��¼����ȫƥ���ʼ��λ��
			j = -1;//����
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
