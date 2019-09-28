#include<iostream>
#include<algorithm>
using namespace std;
int T;
char ss[2][100] = { "light","heavy" };
char s[3][3][10];

bool check(char a, int b)
{
	for (int i = 0; i < 3; i++)
	{
		int ans[2] = { 0,0 };
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; s[i][j][k]; k++)
				if (s[i][j][k] == a) ans[j] += b;
		}
		if (ans[0] == ans[1] && s[i][2][0] != 'e') return false;
		if (ans[0] < ans[1] && s[i][2][0] != 'd') return false;
		if (ans[0] > ans[1] && s[i][2][0] != 'u') return false;
	}
	return true;
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				scanf("%s", s[i][j]);
		for (char i = 'A'; i <= 'L'; i++)
			for (int j = -1; j < 2; j += 2)
				if (check(i, j))
					printf("%c is the counterfeit coin and it is %s.\n", i, ss[max(j, 0)]);
	}
	return 0;
}