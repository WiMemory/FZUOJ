#include<iostream>
#include<algorithm>
using namespace std;
char s1[1005], s2[1005];
int l1, l2, dp[1005][1005];
int main() {
	while (~scanf("%s%s", s1 + 1, s2 + 1)) {
		l1 = strlen(s1 + 1);
		l2 = strlen(s2 + 1);
		for (int i = 0; i <= l2; i++)
			dp[0][i] = 0;
		for (int i = 0; i <= l1; i++)
			dp[i][0] = 0;
		for (int i = 1; i <= l1; i++)
			for (int j = 1; j <= l2; j++) {
				if (s1[i] == s2[j])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		printf("%d\n", dp[l1][l2]);
	}
	return 0;
}