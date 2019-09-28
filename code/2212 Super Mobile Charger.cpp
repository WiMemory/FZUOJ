#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = (int)1e2 + 5;
int val[maxn];

int main() {
	int T, n, cost, i, cnt;
	cin >> T;
	while (T--) {
		cin >> n >> cost;
		cnt = 0;
		for (i = 0; i < n; i++) {
			cin >> val[i];
		}
		sort(val, val + n);
		for (i = n - 1; i >= 0; i--) {
			if (100 - val[i] <= cost) {
				cnt++;
				cost -= (100 - val[i]);
			}
		}
		cout << cnt << endl;
	}
	return 0;
}