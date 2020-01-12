#include <iostream>
#include <set>
using namespace std;

int main() {
	set<int> s;
	s.insert(1);
	s.insert(3);
	s.insert(5);
	
	set<int>::iterator ite;
//	int it;
//	it = s.find(1);
	ite = s.find(1);
	if(ite==s.end()) cout << "NO";
	else cout << "YES";
}
