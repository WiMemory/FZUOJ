#include<iostream>
using namespace std;
int F[50005];
void init() {
	int k = 0, K = 1, t = 1;
	F[0] = 0;
	for (int i = 1; i < 50005; i++)
	{
		F[i] = (F[i - 1] + t) % 10000;
		k++;
		if (k == K)
		{
			K++;
			k = 0;
			t = t * 2 % 10000;
		}
	}
}
int main() {
	int n;
	init();
	while(cin >> n) {
		printf("%d\n", F[n]);
	}
}