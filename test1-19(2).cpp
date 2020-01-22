#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void rec(int i, vector<int>& nums, vector<int>& item, vector<vector<int> >& result) {
	if( i>=nums.size()) {
		return ;
	}
	item.push_back(nums[i]);
	rec(i+1, nums, item, result);
}

int main() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	
	vector<int> item;
	vector<vector<int> > result;
	
	rec(0, nums, item, result);
	for(int i=0; i<result.size(); i++) {
		for(int j=0; j<result[i].size(); j++) {
			cout << result[i][j];
		}
		cout <<endl;
	}
}
