#define gets(x) gets_s(x)
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	char s[10];
	int low = 0, high = 10000000;
	while (scanf("%d", &n) && n) {
		getchar();//µÖÏû»Ø³µ£»
		gets(s);
		if (s[4] == 'h') {
			if (n < high)
				high = n;
		}
		else if (s[4] == 'l') {
			if (n > low)
				low = n;
		}
		else {
			if (n > low && n < high)
				printf("The guy may be honest\n");
			else
				printf("The guy is dishonest\n");
			low = 0, high = 10000000;
		}
	}
	return 0;
}