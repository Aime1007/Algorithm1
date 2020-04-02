#include<iostream>
#include<algorithm>
using namespace std;
struct homework {
	int d, s;
}list[1001];
bool cmp(homework a, homework b) {
	return a.s > b.s;
}
bool flag[100001] = { false };
int main()
{
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < 100001; i++)
			flag[i] = false;
		for (int i = 0; i < n; i++)
			cin >> list[i].d;
		for (int i = 0; i < n; i++)
			cin >> list[i].s;
		sort(list, list + n, cmp);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int j = list[i].d;
			while (flag[j]) {
				j--;
			}
			if (j == 0) {
				ans += list[i].s;
			}
			else {
				flag[j] = true;
			}
		}
		cout << ans << endl;
	}
	//system("pause");
	return 0;
}
