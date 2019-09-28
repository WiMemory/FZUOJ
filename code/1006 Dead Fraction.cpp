#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string s;
int qpow(int x, int y)
{
	int res = 1;
	while (y)
	{
		if (y & 1) res = res * x;
		x = x * x;
		y = y >> 1;
	}
	return res;
}
int gcd(int x, int y)
{
	return y == 0 ? x : gcd(y, x%y);
}
int main()
{
	while (cin >> s)
	{
		if (s == "0") break;
		int mina, minb;
		mina = minb = 0x3f3f3f3f;
		int l = 0;
		int all = 0;
		for (int i = 2; s[i] != '.'; i++)
		{
			all = all * 10 + s[i] - '0';
			l++;
		}
		int num = all;
		int k = 1;
		for (int i = 1; i <= l; i++)
		{
			num = num / 10;
			k = k * 10;
			int a = all - num;
			int b = qpow(10, l - i)*(k - 1);
			int j = gcd(a, b);
			if (b / j < minb)
			{
				mina = a / j;
				minb = b / j;
			}
		}
		printf("%d/%d\n", mina, minb);
	}
	return 0;
}