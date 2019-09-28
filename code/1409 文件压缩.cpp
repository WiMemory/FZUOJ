#include<iostream>
#include<algorithm>
using namespace std;
struct Node
{
	char s, e;
	bool flag;
}node[10001];
bool cmp(Node n1, Node n2)
{
	return n1.s < n2.s;
}
int main()
{
	int n, i, p;
	char c[10001];
	while (scanf("%d%s", &n, c) != EOF)
	{
		if (n == 1) { printf("%s\n1\n", c); continue; }
		for (i = 0; i < n; i++)
		{
			node[i].s = c[i];
			node[i].e = c[(n + i - 1) % n];
			if (i == 1) node[i].flag = true;
			else node[i].flag = false;
		}
		stable_sort(node, node + n, cmp);
		for (i = 0; i < n; i++)
		{
			if (node[i].flag == true) p = i + 1;
			printf("%c", node[i].e);
		}
		printf("\n%d\n", p);
	}
	return 0;
}