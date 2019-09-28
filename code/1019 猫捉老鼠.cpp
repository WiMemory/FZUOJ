#include <iostream>
#include <cstdio>
using namespace std;

struct Point
{
	int x, y;
}mou, cat; //mouse，cat的坐标
int dm, dc; //分别为mouse和cat面朝的方向,0北，1东，2南，3西
char map[10][11]; //切记预留一位存储‘\0’！T_T
int t;//时间


void Move(Point &animal, int &d)
{
	int X, Y;
	if (d == 0)
	{
		X = animal.x, Y = animal.y;
		if (!Y || map[Y - 1][X] == '*')
			d++;
		else
			animal.y--;
	}
	else if (d == 1)
	{
		X = animal.x + 1, Y = animal.y;
		if (map[Y][X] == '\0' || map[Y][X] == '*')
			d++;
		else
			animal.x++;
	}
	else if (d == 2)
	{
		X = animal.x, Y = animal.y;
		if (Y == 9 || map[Y + 1][X] == '*')
			d++;
		else
			animal.y++;
	}
	else
	{
		X = animal.x, Y = animal.y;
		if (!X || map[Y][X - 1] == '*')
			d = 0;
		else
			animal.x--;
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		t = dm = dc = 0;
		for (int i = 0; i < 10; i++)
		{
			scanf("%s", map[i]);
		}
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
			{
				if (map[i][j] == 'c')
				{
					cat.y = i;
					cat.x = j;
				}
				if (map[i][j] == 'm')
				{
					mou.y = i;
					mou.x = j;
				}
			}
		while (1)
		{
			t++;
			Move(cat, dc);
			Move(mou, dm);
			if (cat.x == mou.x && cat.y == mou.y) break;
			if (t > 500)
			{
				t = 0;
				break;
			}
		}
		printf("%d\n", t);
	}
	return 0;
}