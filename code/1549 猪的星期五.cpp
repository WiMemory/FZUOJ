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
		int blag = check(i + 1900 - 1);    //�жϵ�ǰ����Ƿ�Ϊ���� 
		for (int p = 0; p < 12; p++)         //һ��12���½����ж�13�շֱ������ڼ� 
		{
			if (p == 2)            //������˵���������Ҫ����blag��ֵ 
				day += blag;
			s[i][(day + 13) % 7]++;      //�Ѷ�Ӧ��ǰ��p-1���µ����Ӽ���13��7ȡģ 
			day += a[p];          //���ϵ�ǰ�·ݵ����� 
		}
		for (int j = 0; j <= 6; j++)
			s[i][j] += s[i - 1][j];  //s[k][j]��ʾǰk�������j������ 
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