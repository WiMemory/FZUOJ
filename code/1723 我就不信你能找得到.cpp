#include<stdio.h>
#include<algorithm>
using namespace std;
__int64 a[1000002];
int main()
{
	__int64 m, n, i, j, s, k, t;
	scanf("%I64d", &t);
	while (t--)
	{
		scanf("%I64d", &n);
		s = 0;
		for (i = 0; i < n; i++) {
			scanf("%I64d", &a[i]);
			s ^= a[i];
		}
		//��ʱ��s������Ϊ�����������������
		//������Ҫ��s����������������������֮һ����һ����򣬱���Եõ�����һ������
		//����Ϊs�Ķ������е�iλ���Ϊ1�������������ĵ�iλ��Ȼһ��Ϊ1��һ��Ϊ0
		//���Ա�����������ĵ�iλΪ1������������s������򣬱���Եõ�����һ������
		m = s, k = s, j = 0;
		//�ҵ�m������������һλ1
		while (m) {
			j++;
			if (m % 2 == 1) break;
			m /= 2;
		}
		j--;
		for (i = 0; i < n; i++)
			if (a[i] >> j & 1)
				s ^= a[i];
		k ^= s;
		printf("%I64d %I64d\n", min(k, s), max(k, s));
	}
	return 0;
}