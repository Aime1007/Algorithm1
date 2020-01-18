#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int child = 0;
        int cookie = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while( child <g.size() && cookie <s.size()) {
        	if(g[child] <= s[cookie]) {
        		child ++;
        		cookie ++;
			}
			else if(g[child] > s[cookie]) {
				cookie ++;
			}
		}
		return child;
    }
};

int main() {
	Solution solve;
	vector<int> g;
	vector<int> s;
	g.push_back(5);
	g.push_back(10);
	g.push_back(2);
	g.push_back(9);
	g.push_back(15);
	g.push_back(9);
	s.push_back(6);
	s.push_back(1);
	s.push_back(20);
	s.push_back(3);
	s.push_back(8);
	cout << solve.findContentChildren(g, s);
}
