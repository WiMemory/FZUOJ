#include<iostream>
#include<string>
#include<cmath>
#include<cstdio>
using namespace std;

int main() {
	int x0, y0, x1, x2, y1, y2, time;
	double dist = 0.0, d;
	string str;
	char *p;
	while (cin >> x0 >> y0) {//x0,y0 is useless, but still need to be read in
		cin.get();//read the line feed
		dist = 0.0;
		while (getline(cin, str) && str != "java") {
			p = &str[0];//change a string to a char point!!
			sscanf(p, "%d%d%d%d", &x1, &y1, &x2, &y2);
			d = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
			dist += sqrt(d);//add the lenth of street
		}
		dist = dist * 2 / 1000.0 / 20.0 * 60.0;//every street has two sides
		time = int(dist + 0.5);//convert double to int
		cout << time / 60 << ':';
		if (time % 60 < 10)cout << '0' << time % 60 << endl;
		else cout << time % 60 << endl;
	}
	return 0;
}