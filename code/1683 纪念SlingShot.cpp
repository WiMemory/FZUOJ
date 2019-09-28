#include <cstdio>
#include <cstring>
using namespace std;
#define MOD 2009
#define N	4
const int NUM = sizeof(int)*N*N;

void MUL(int a[][N], int b[][N], int c[][N])
{
	int i, j;
	for (i = 0; i < N; i++) for (j = 0; j < N; j++)
		c[i][j] = (a[i][0] * b[0][j] + a[i][1] * b[1][j]
			+ a[i][2] * b[2][j] + a[i][3] * b[3][j]) % MOD;
}

void POW(int b, int P[][N])
{
	int A[N][N] = { {1,3,2,7},{0,3,2,7},{0,1},{0,0,1} }, T[N][N];

	memset(P, 0, NUM);
	for (int i = 0; i < N; i++) P[i][i] = 1;

	while (b)
	{
		if (b & 1)
		{
			MUL(P, A, T);
			memcpy(P, T, NUM);
		}
		b >>= 1;
		MUL(A, A, T);
		memcpy(A, T, NUM);
	}
}

int main()
{
	int t, T, n, P[N][N], ans;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		scanf("%d", &n);
		if (n == 0) ans = 1;
		else if (n == 1) ans = 4;
		else
		{
			POW(n - 2, P);
			ans = (9 * P[0][0] + 5 * P[0][1] + 3 * P[0][2] + P[0][3]) % MOD;
		}
		printf("Case %d: %d\n", t, ans);
	}
	return 0;
}