#include<queue>
#include<cstdio>
using namespace std;
const int maxn = 1005;
int x, y, n;
char s[maxn];

struct query
{
	int id, now, t;
	query(int id, int now, int t) :id(id), now(now), t(t) {}
	
	bool operator < (const query q) const {
		if (now == q.now) return id > q.id;
		return now > q.now;
	}
};

int main()
{
	priority_queue<query> p;
	while (~scanf("%s", s), s[0] != '#')
	{
		scanf("%d%d", &x, &y);
		p.push(query(x, y, y));
	}
	scanf("%d", &n);
	while (n--)
	{
		query q = p.top(); p.pop();
		printf("%d\n", q.id);
		q.now += q.t;
		p.push(q);
	}
	return 0;
}