#include<iostream>
using namespace std;
int main() {
	int T;
	double S, H, Vx, Vy;
	cin >> T;
	while (T--) {
		cin >> S >> H >> Vx >> Vy;
		double hh = Vy * (S / Vx) - 0.5*10.0*(S / Vx)*(S / Vx);
		if (hh >= H)
			printf("good done!\n");
		else
			printf("poor Merida!\n");
	}
}