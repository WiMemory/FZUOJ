#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1010;
int a[N];
int t, n;
int g[N][N];//边的权值
int lowcost[N];//加入生成树的最小花费
bool vis[N];//标记节点是否加入最小生成树
const int INF = 0x3f3f3f3f;
void init() {
	memset(a, 0, sizeof(a));
	memset(g, 0, sizeof(g));
	memset(lowcost, 0, sizeof(lowcost));
	memset(vis, false, sizeof(vis));
}
int prim() {
	int Min = INF;
	int pos = 1;
	int ans = 0;
	vis[pos] = true;
	//遍历和pos相邻的节点，权值存入lowcost
	for (int i = 1; i <= n; i++) {
		if (i != pos) {
			lowcost[i] = g[pos][i];
		}
	}
	//将剩下n-1个节点加入生成树
	for (int i = 1; i < n; i++) {
		Min = INF;
		//找出当前所有未加入生成树节点中最小权值的节点
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && lowcost[j] < Min) {
				Min = lowcost[j];
				pos = j;
			}
		}
		ans += Min;
		vis[pos] = true;
		//生成树发生变化，修改权值
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && lowcost[j] > g[pos][j]) {
				lowcost[j] = g[pos][j];
			}
		}
	}
	return ans;
}
int main(void) {
	scanf("%d", &t);
	while (t--) {
		init();
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &g[i][j]);
				//将网关适配器的价格加入边的权值中
				g[i][j] += (a[i] + a[j]);
			}
		}
		int ans = prim();
		printf("%d\n", ans);
	}
	return 0;
}