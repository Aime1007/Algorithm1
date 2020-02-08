#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int N;
int M;
int K;
set<int> s[55];
int main() {
	cin >>N;
	for(int i=0; i<N; i++) {
		cin >>M;
		for(int j=0; j<M; j++) {
			int a;
			cin >> a;
			s[i].insert(a);
		}
	}
	
	cin >>K;
	for(int k=0; k<K; k++) {
		int a,b;
		cin >>a >>b;
		int Nc=0;
		a--; b--;
		for(multiset<int>::iterator it=s[a].begin(); it!= s[a].end(); it++) {
			if(s[b].find(*it) != s[b].end()) {
				Nc++;
			}
		}
		int Nt=s[a].size()+s[b].size()-Nc;
		float ans=1.0*Nc/Nt*100;
		printf("%.2f%\n", ans);
	}
}
