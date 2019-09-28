#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int gcd(int n, int m)
{
	if (n < m)return gcd(m, n);
	if (m == 0)return n;
	else return gcd(m, n%m);
}
int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		string in;
		cin >> in;
		int interge = 0, decimal = 0, flag = 0, dig = 0;
		for (int i = 0; i < in.length(); i++)
		{
			if (in[i] == '.') { flag = 1; continue; }
			if (flag == 0)
			{
				if (in[i] <= '9'&&in[i] >= '0')
					interge = interge * 10 + in[i] - '0';
			}
			else
			{
				if (in[i] <= '9'&&in[i] >= '0') {
					dig++;
					decimal = decimal * 10 + in[i] - '0';
				}
			}
		}
		int k = 1;
		for (int i = 0; i < dig; i++)k *= 10;
		int gg = gcd(k, decimal);
		k /= gg;
		decimal /= gg;
		interge = interge * k + decimal;
		printf("%d/%d\n", interge, k);
	}
}