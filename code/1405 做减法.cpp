#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
	int a, b, c;
	char str[100], ch[100];
	while (cin >> a >> b)
	{
		c = abs(a - b);
		sprintf(str, "%d", c);//Êý×Ö×ª×Ö·û´®
		int len = strlen(str);
		int num = 0;
		int count = 1;
		for (int i = len - 1; i >= 0; i--)
		{
			ch[num++] = str[i];
			if (i > 0 && count % 3 == 0) ch[num++] = ',';
			count++;
		}
		if (a - b < 0) cout << "-";
		for (int i = num - 1; i >= 0; i--) cout << ch[i];
		cout << endl;
		memset(ch, ' ', sizeof(ch));
		memset(str, ' ', sizeof(str));
	}
	return 0;
}