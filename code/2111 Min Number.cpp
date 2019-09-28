#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	char num[20000];
	int len, t, m, k, i, j;
	cin >> t;
	while (t--)
	{
		cin >> num >> m;
		len = strlen(num);
		if (m != 0)
		{
			for (i = 0, k = 0; i < len; i++)
			{
				//搜索除0以外的最小值，应当注意把num[0]交换到尽量后面
				if (num[i] <= num[k] && num[i] != '0')
				{
					k = i;
				}
			}
			if (num[0] > num[k])
			{
				swap(num[0], num[k]);//交换
				m--;
			}
		}
		for (i = 1; i < len && m != 0; i++)//从第二位开始找
		{
			//如为0 则不必处理
			if (num[i] == '0') {
				continue;
			}
			for (j = i, k = j; j < len; j++)//查找最小值
			{
				//同理此处应当注意把num[i]交换到尽量后面
				if (num[j] <= num[k])
				{
					k = j;
				}
			}
			if (num[i] > num[k])
			{
				swap(num[i], num[k]);//交换
				m--;
			}
		}
		cout << num << endl;
	}
	return 0;
}