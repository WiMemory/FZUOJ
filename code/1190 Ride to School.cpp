#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int N;
	double v, t, x, min;
	while (cin >> N) {
		if (N == 0) break;
		min = 1e100;
		for (int i = 0; i < N; i++) {
			cin >> v >> t;
			x = t + 4.5 / v * 3600;
			if (t >= 0 && x < min) min = x;
		}
		cout << ceil(min) << endl;
	}
	return 0;
}