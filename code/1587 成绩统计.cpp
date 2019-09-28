#include<iostream>
using namespace std;
int box[101] = { 0 };
int main() {
	int N, goal, Q, L, H, i, ans, j;
	while (cin >> N) {
		for (i = 0; i < N; i++) {
			cin >> goal;
			++box[goal];
		}
		cin >> Q;
		for (i = 0; i < Q; i++) {
			ans = 0;
			cin >> L >> H;
			for (j = L; j <= H; j++) {
				ans += box[j];
			}
			cout << ans << endl;
		}
		memset(box, 0, sizeof(box));
	}
}