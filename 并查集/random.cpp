#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	srand((unsigned)time(0));
	int n;
	n=rand()%200+1;
	cout<<n<<endl;
	for(int i=1; i<=n; i++) {
		cout<<rand()%200+1<<" ";
	}
} 
