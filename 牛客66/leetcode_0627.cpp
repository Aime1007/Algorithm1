#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
const int maxn=1e5;

int main() {
	vector<int> nums;
	for(int i=0; i<4; i++) {
		cin>>nums[i];
	}
	int max=0,l1,l2;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==0) {
                int cnt=0;
                for(int j=i+1; j<nums.size(); j++) {
                    
                    if(nums[j]==0 || j==nums.size()-1) {
                        l1=cnt;
                        break;
                    }
                    cnt++;
                }
                cnt=0;
                for(int j=i-1; j>=0; j--) {

                    if(nums[j]==0 || j==0) {
                        l2=cnt;
                        break;
                    }
                    cnt++;
                }
                if(max<l1+l2) {
                    cout<<"l1:"<<l1<<endl;
                    cout<<"l2:"<<l2<<endl;
                    max=l1+l2;
                }
            }
        }
    cout<<max<<endl;
	return 0;
}

