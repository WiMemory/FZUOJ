#include <iostream>
int y1[2] = { 298,299 }, y2[2] = { 365,366 }; //y1存校庆是当年的第几天
int Yeap(int year);
int Which(int y, int m, int d);
int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int y, m, d, day, th = 50, left;
		scanf("%d %d %d", &y, &m, &d);
		day = Which(y, m, d);
		if (day - y1[Yeap(y)] > 0) {//如果已经超过当年的校庆日，则要算离下个校庆日差几天
			th += y - 2008 + 1;
			left = y2[Yeap(y)] - day + y1[Yeap(y + 1)];//当年总天数-实际天数+下一年的校庆日
		}
		else {
			th += y - 2008;
			left = y1[Yeap(y)] - day;
		}
		printf("%d days left for celebrating the %dth anniversary of the founding of Fuzhou University!\n", left, th);
	}
	return 0;
}
int Yeap(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 1;
	return 0;
}

int Which(int y, int m, int d) {//根据年月日算是当年的第几天
	int s = 0;
	switch (m)
	{
	case 12:s += 30;
	case 11:s += 31;
	case 10:s += 30;
	case 9:s += 31;
	case 8:s += 31;
	case 7:s += 30;
	case 6:s += 31;
	case 5:s += 30;
	case 4:s += 31;
	case 3:Yeap(y) ? s += 29 : s += 28;
	case 2:s += 31;
	case 1:s += d;
	}
	return s;
}