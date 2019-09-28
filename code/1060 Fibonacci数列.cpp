#include <iostream>
#include <string>
using namespace std;

void add(char a[], char b[], int m, int n)
{
	int flag = 0; int temp, i;
	for (i = 0; i < m || i < n; i++)
	{
		if (a[i] == '\0')
			a[i] = '0';
		if (b[i] == '\0')
			b[i] = '0';
		temp = a[i] - 48 + b[i] - 48 + flag;
		flag = 0;
		if (temp > 9)
			flag = 1;
		b[i] = temp % 10 + 48;
	}
	if (flag == 1)
		b[i] = '1';
}
int main()
{
	int number, i;
	char a[1001], b[1001];
	while (cin >> number)
	{
		memset(a, '\0', sizeof(a));
		memset(b, '\0', sizeof(b));
		a[0] = '1'; b[0] = '1';
		for (i = 3; i <= number; i++)
		{
			if (i % 2 != 0)
				add(a, b, strlen(a), strlen(b));
			else
				add(b, a, strlen(a), strlen(b));
		}
		if ((i - 1) % 2 != 0)
			for (int j = strlen(b) - 1; j < strlen(b); j--)
				cout << b[j];
		else
			for (int k = strlen(a) - 1; k < strlen(a); k--)
				cout << a[k];
		cout << endl;
	}
	return 0;
}