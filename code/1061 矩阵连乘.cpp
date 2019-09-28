#include<stack>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1e4;
int T, n, tot = 26, flag, ans;
char s[maxn];

struct rec
{
	int x, y;
	rec(int x = 0, int y = 0) :x(x), y(y) {}
	void read() { scanf("%d%d", &x, &y); }
}a[maxn];

rec operator*(rec a, rec b)
{
	if (a.y != b.x) flag = 0;
	ans += a.x*a.y*b.y;
	return rec(a.x, b.y);
}

int main()
{
	while (~scanf("%d", &n))
	{
		flag = 1;	ans = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%s", s);
			a[s[0] - 'A'].read();
		}
		scanf("%s", s);
		stack<int> p, q;
		for (int i = 0; s[i]; i++)
		{
			if (s[i] == '(')  p.push(-1);
			else if (s[i] == ')')
			{
				while (p.top() != -1) { q.push(p.top()); p.pop(); }
				p.pop();	int k = q.top();	q.pop();
				while (!q.empty())
				{
					a[++tot] = a[k] * a[q.top()];
					k = tot;	q.pop();
				}
				p.push(k);
			}
			else p.push(s[i] - 'A');
		}
		while (!p.empty()) { q.push(p.top()); p.pop(); }
		int k = q.top();	q.pop();
		while (!q.empty())
		{
			a[++tot] = a[k] * a[q.top()];
			k = tot;	q.pop();
		}
		if (flag) printf("%d\n", ans);
		else printf("error\n");
	}
	return 0;
}