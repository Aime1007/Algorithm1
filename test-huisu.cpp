#include <iostream>
#include <vector>
using namespace std;

vector<int> nums;
vector<int> item;
vector<vector<int> > result;
void generate(int i) {
	if(i>=nums.size()) {
		return;
	}
	item.push_back(nums[i]);
	result.push_back(item);
	generate(i+1);
	item.pop_back();
	generate(i+1);
}
int main() {
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	result.push_back(item);
	generate(0);
	
}
