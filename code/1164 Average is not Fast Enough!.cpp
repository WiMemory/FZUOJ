#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n, t, h, m, s, tot;
	double d;
	bool flag;
	scanf("%d %lf", &n, &d);
	while (cin >> t)
	{
		flag = 1;
		tot = 0;
		for (int i = 0; i < n; i++)
		{
			char ch1;
			cin >> ch1;
			if (ch1 == '-')
			{
				cin >> ch1 >> ch1 >> ch1 >> ch1 >> ch1 >> ch1;
				flag = 0;
				continue;
			}
			else
			{
				scanf("%*c%d%*c%d", &m, &s);
				tot += (s + m * 60 + (ch1 - '0') * 3600);
			}
		}
		if (!flag) printf("%3d: -\n", t); //3λ�Ŀ��
		else
		{
			int ave = 1.0*tot / d + 0.5; //��������ķ���
			m = ave / 60;
			s = ave % 60;
			printf("%3d: %d:%02d min/km\n", t, m, s); //ע����������%02d
		}
	}
	return 0;
}