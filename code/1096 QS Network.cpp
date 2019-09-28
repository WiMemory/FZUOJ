#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1010;
int a[N];
int t, n;
int g[N][N];//�ߵ�Ȩֵ
int lowcost[N];//��������������С����
bool vis[N];//��ǽڵ��Ƿ������С������
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
	//������pos���ڵĽڵ㣬Ȩֵ����lowcost
	for (int i = 1; i <= n; i++) {
		if (i != pos) {
			lowcost[i] = g[pos][i];
		}
	}
	//��ʣ��n-1���ڵ����������
	for (int i = 1; i < n; i++) {
		Min = INF;
		//�ҳ���ǰ����δ�����������ڵ�����СȨֵ�Ľڵ�
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && lowcost[j] < Min) {
				Min = lowcost[j];
				pos = j;
			}
		}
		ans += Min;
		vis[pos] = true;
		//�����������仯���޸�Ȩֵ
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
				//�������������ļ۸����ߵ�Ȩֵ��
				g[i][j] += (a[i] + a[j]);
			}
		}
		int ans = prim();
		printf("%d\n", ans);
	}
	return 0;
}