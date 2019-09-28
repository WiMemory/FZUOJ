#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
double Dis(double x1, double y1, double x2, double y2) {
	double X = (x1 - x2)*(x1 - x2);
	double Y = (y1 - y2)*(y1 - y2);
	return sqrt(X + Y);
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		double x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double dis = Dis(x1, y1, x2, y2);
		if (r2 < r1) swap(r1, r2);
		if (x1 == x2 && y1 == y2 && r1 == r2) cout << "-1" << endl;
		else if (dis > r1 + r2) cout << "4" << endl;//外离 
		else if (dis == r2 + r1) cout << "3" << endl;//外切 
		else if (dis > r2 - r1 && dis < r2 + r1) cout << "2" << endl;//相交 
		else if (dis == r2 - r1) cout << "1" << endl;//内交 
		else if (dis < r2 - r1) cout << "0" << endl;//内含 
	}
	return 0;
}