#include<iostream>
#include<cstring>
using namespace std;

#define maxn 1010
char str[maxn][maxn];
char p[maxn], ext[maxn];
int main()
{
	int tot;
	int n, m;
	scanf("%d", &tot);
	while (tot--)
	{
		scanf("%d%d", &n, &m);
		getchar();
		for (int i = 0; i < n; i++)
		{
			scanf("%s", &str[i]);
		}
		for (int i = 0; i < m; i++)
		{
			scanf("%s%s", p, ext);
			for (int j = 0; j < n; j++)
			{
				int a = 0, flag = 1;
				for (int k = 0; p[k]; k++)
				{
					if (str[j][a] != p[k])
					{
						flag = 0;
						break;
					}
					a++;
				}
				if (flag)
				{
					flag = 1;
					int a = strlen(ext) - 1;
					for (int k = strlen(str[j]) - 1; ext[a]; k--)
					{
						if (str[j][k] != ext[a])
						{
							flag = 0;
							break;
						}
						a--;
					}
				}
				if (flag)
					printf("%s\n", str[j]);
			}
		}
	}
	return 0;
}