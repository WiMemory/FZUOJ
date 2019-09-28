#include<iostream>
using namespace std;
int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		for (int i = 1; i <= m; i++)
		{
			int s, t, r;
			scanf("%d%d%d", &s, &t, &r);
			int sum = 0;

			for (int j = 0; j < n;)
			{
				if (j != 0)sum += r;
				if (j + s * t < n)
				{
					j += s * t;
					sum += t;
				}
				else
				{
					if ((n - j) / s != ((n - j) / (s*1.0)))
						sum += (n - j) / s + 1;
					else
						sum += (n - j) / s;
					break;
				}
			}
			cout << sum << endl;
		}
	}
	return 0;
}