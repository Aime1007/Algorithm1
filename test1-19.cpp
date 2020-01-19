#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	
	vector<int> item;
	vector<vector<int> > result;
	for(int i=0; i<nums.size(); i++) {
		item.push_back(nums[i]);
		result.push_back(item);
	}
	
	for(int i=0; i<result.size(); i++) {
		for(int j=0; j<result[i].size(); j++) {
			cout << result[i][j];
		}
		cout <<endl;
	}
}
