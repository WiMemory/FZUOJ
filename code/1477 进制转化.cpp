#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n, k, i;
	vector<int> ans;
	while (scanf("%d%d", &n, &k) != EOF) {
		ans.clear();
		if (n == 0) {
			printf("0\n");
			continue;
		}
		for (i = 0; n != 0; i++) {
			ans.push_back(n%k);
			n /= k;
		}
		for (--i; i >= 0; i--) {
			if (ans[i] >= 10) {
				printf("%c", ans[i] - 10 + 'A');
			}
			else {
				printf("%c", ans[i] + '0');
			}
		}
		cout << endl;
	}
	return 0;
}