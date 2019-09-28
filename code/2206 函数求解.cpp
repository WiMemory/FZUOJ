#include<stdio.h>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		if (n < 20150001)printf("%d\n", n + 2014);
		else printf("%d\n", 20152014);
	}
}