#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a, b;
	char m[1001][17];
	char words[20];
	int n[1001];
	int money[101];
	memset(money, 0, 101);
	cin >> a >> b;
	for (int i = 0; i < a; i++)
		cin >> m[i] >> n[i];
	for (int j = 0; j < b; j++)
	{
		while (cin >> words)
		{
			if (words[0] == '.')
			{
				break;
			}
			for (int k = 0; k < a; k++)
			{
				if (strcmp(words, m[k]) == 0)
					money[j] = money[j] + n[k];
			}
		}
	}
	for (int p = 0; p < b; p++)
	{
		cout << money[p] << endl;
	}
	return 0;
}