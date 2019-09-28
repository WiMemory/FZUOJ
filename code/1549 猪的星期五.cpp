#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int s[1005][15];
int check(int year)
{
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		return 1;
	return 0;
}

int main()
{
	int day = 1;
	memset(s, 0, sizeof(s));
	for (int i = 1; i <= 400; i++)
	{
		int blag = check(i + 1900 - 1);    //判断当前年份是否为闰年 
		for (int p = 0; p < 12; p++)         //一年12个月进行判断13日分别是星期几 
		{
			if (p == 2)            //如果到了第三个月需要加上blag的值 
				day += blag;
			s[i][(day + 13) % 7]++;      //把对应的前面p-1个月的日子加上13对7取模 
			day += a[p];          //加上当前月份的天数 
		}
		for (int j = 0; j <= 6; j++)
			s[i][j] += s[i - 1][j];  //s[k][j]表示前k年的星期j的天数 
	}
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < 6; i++)
			cout << s[n][i] << " ";
		cout << s[n][6] << endl;
	}
	return 0;
}