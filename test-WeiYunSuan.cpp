#include <iostream>
#include <vector>
using namespace std;

vector<int> nums;
vector<vector<int> > result;

int main() {
	int all = 1<<nums.size();
	
	for(int i=0; i<all; i++) {
		vector<int> item;
		for(int j=0; j<nums.size(); j++) {
			if( i&(1<<j)) {
				item.push_back(nums[j]);
			}
		}
		result.push_back(item);
	}
	
	for(int i=0; i<result.size(); i++) {
		for(int j=0; j<result[i].size(); j++) {
			cout<< result[i][j];
		}
		cout<<endl;
	}
}
