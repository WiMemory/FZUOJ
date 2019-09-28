#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct num
{
	char chu[10];
	double result;
};

bool my_sort(num a, num b)
{
	return a.result < b.result;
}

//返回最大公因数，返回1则互质
int ishuzhi(int a, int b)
{
	if (a%b == 0)
		return b;
	else
		return ishuzhi(b, a%b);
}

int main()
{
	vector<num> t_vec;
	int n, i, j;
	num nnn;
	vector<num>::iterator it;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= i; j++)
			{
				if (ishuzhi(j, i) == 1)
				{
					nnn.result = (double)j / (double)i;
					sprintf(nnn.chu, "%d/%d", j, i);
					t_vec.push_back(nnn);
				}
			}
		}
		sort(t_vec.begin(), t_vec.end(), my_sort);
		it = t_vec.begin();
		printf("0/1\n");
		for (; it != t_vec.end(); it++)
			printf("%s\n", it->chu);
		t_vec.clear();
	}
	return 0;
}