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
				//������0�������Сֵ��Ӧ��ע���num[0]��������������
				if (num[i] <= num[k] && num[i] != '0')
				{
					k = i;
				}
			}
			if (num[0] > num[k])
			{
				swap(num[0], num[k]);//����
				m--;
			}
		}
		for (i = 1; i < len && m != 0; i++)//�ӵڶ�λ��ʼ��
		{
			//��Ϊ0 �򲻱ش���
			if (num[i] == '0') {
				continue;
			}
			for (j = i, k = j; j < len; j++)//������Сֵ
			{
				//ͬ��˴�Ӧ��ע���num[i]��������������
				if (num[j] <= num[k])
				{
					k = j;
				}
			}
			if (num[i] > num[k])
			{
				swap(num[i], num[k]);//����
				m--;
			}
		}
		cout << num << endl;
	}
	return 0;
}