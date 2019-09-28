#include<iostream>
using namespace std;
int main()
{
	int t[2][100], i, k, n, Case;
	bool flag;
	cin >> Case;
	while (Case--)
	{
		cin >> n;
		for (i = 0; i < n; ++i)
			cin >> t[0][i];
		k = 0;
		flag = true;
		while (flag)
		{
			t[(k + 1) % 2][n - 2] = t[k][n - 1];
			for (i = n - 4; i >= 0; i -= 2)
				t[(k + 1) % 2][i] = t[k][i + 1] - t[(k + 1) % 2][i + 2];
			if (i == -2)
			{
				i = 1;
				t[(k + 1) % 2][1] = t[k][0] - t[(k + 1) % 2][0];
			}
			else if (i == -1)
			{
				i = 0;
				t[(k + 1) % 2][0] = t[k][0] - t[(k + 1) % 2][1];
			}
			for (i += 2; i <= n - 1; i += 2)
				t[(k + 1) % 2][i] = t[k][i - 1] - t[(k + 1) % 2][i - 2];
			for (i = 0; i <= n - 1; ++i)
			{
				if (t[(k + 1) % 2][i] < 0)
					flag = false;
				else
					k = (k + 1) % 2;
			}
		}
		for (i = 0; i <= n - 2; ++i)
			cout << t[k][i] << " ";
		cout << t[k][n - 1] << endl;
	}
	return 0;
}