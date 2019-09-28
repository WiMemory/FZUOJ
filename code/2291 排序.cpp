#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1e5 + 100;
int a[maxn], b[maxn], c[maxn];
int n;

int main()
{
	while (~scanf("%d", &n))
	{
		int cnt = 0, tot = 0;
		for (int i = 1; i <= n; i++)
		{
			int v;
			scanf("%d", &v);
			if (i & 1)
				a[tot++] = v;
			else
				b[cnt++] = v;
		}
		sort(a, a + tot);
		sort(b, b + cnt);
		int x = 0, y = 0;
		for (int i = 1; i <= tot + cnt; i++)
		{
			if (i & 1) c[i] = a[x++];
			else c[i] = b[y++];
			// cout<<c[i]<<" ";
		}
		// cout<<endl;
		int ans = 0;
		for (int i = 1; i < tot + cnt; i++)
			if (c[i] > c[i + 1])
			{
				ans = i;
				break;
			}
		if (ans) printf("%d\n", ans);
		else printf("OK\n");
	}
	return 0;
}