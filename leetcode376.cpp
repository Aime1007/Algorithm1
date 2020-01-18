#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if( nums.size()<2) {
        	return nums.size();
		}
		const int begin =0;
		const int up =1;
		const int down =2;
		int state =begin;
		int length =1;
		for(int i=1; i<nums.size(); i++) {
			switch(state) {
				case begin: {
					if( nums[i]>nums[i-1]) {
						state = up;
						length++;
					}
					else if( nums[i]<nums[i-1]) {
						state = down;
						length++;
					}
					break;
				}
				case up: {
					if( nums[i]<nums[i-1]) {
						state = down;
						length++;
					}
					break;
				}
				case down: {
					if( nums[i]>nums[i-1]) {
						state = up;
						length++;
					}
					break;
				}
			}
		}
		return length;
    }
}; 

int main() {
	
}
