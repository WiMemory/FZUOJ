#include<stdio.h>
#define POW(a) a*a
int length(int n)
{
	int i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return i;
}
int main()
{
	int n, t, tlen, tmp, i;
	char c[11];
	while (scanf("%d", &n) != EOF && n != 0)
	{
		t = tlen = 0;
		i = 1;
		tlen = length(POW(i));
		while ((t + tlen * POW(i)) < n)
		{
			t += tlen * POW(i);
			i++;
			tlen = length(POW(i));
		}
		t = n - t;
		t %= tlen;
		if (t == 0) t = tlen;
		tmp = POW(i);
		sprintf(c, "%d", tmp);
		printf("%c\n", c[t - 1]);
	}
	return 0;
}