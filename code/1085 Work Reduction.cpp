#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int t, n, m, l;
struct Work {
	char name[20];
	int a, b;
	int value;
} w[105];
int cmp(Work aa, Work bb) {
	if (aa.value != bb.value)
		return aa.value < bb.value;
	if (strcmp(aa.name, bb.name) < 0)
		return 1;
	else
		return 0;
}
void solve(int nn) {
	int num = n;
	while (num / 2 >= m) {
		if (w[nn].b < (num - num / 2) * w[nn].a)
			w[nn].value += w[nn].b;
		else
			w[nn].value += w[nn].a * (num - num / 2);
		num /= 2;
	}
	w[nn].value += (num - m) * w[nn].a;
}
int main() {
	int Case = 1;
	scanf("%d", &t);
	while (t--) {
		memset(w, 0, sizeof(w));
		scanf("%d%d%d%*c", &n, &m, &l);
		for (int i = 0; i < l; i++) {
			char c; int j = 0;
			while ((c = getchar()) != EOF && c != ':') {
				w[i].name[j++] = c;
			}
			w[i].name[j] = '\0';
			scanf("%d%*c%d%*c", &w[i].a, &w[i].b);
		}
		for (int i = 0; i < l; i++) {
			solve(i);
		}
		sort(w, w + l, cmp);
		printf("Case %d\n", Case++);
		for (int i = 0; i < l; i++)
			printf("%s %d\n", w[i].name, w[i].value);
	}
	return 0;
}